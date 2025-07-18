"""
Script to query an OpenAI API to generate code.
Set environment variable OPENAI_KEY with your API key
before running this script.
"""

import argparse
import json
import os
import time
from pathlib import Path
from typing import Dict, Tuple

import numpy as np
import openai
import tiktoken
from jsonlines import jsonlines
from openai import OpenAI
from openai.types.chat import ChatCompletion
from tqdm import tqdm
from rq2.tcav.perturbator import Perturbator
from common import env_loader
from common.MAD.interactive import call_mad

# from common.utils import get_sample

SLEEP_SECOND = 2.8  # minimum time to sleep with API errors
MAX_SLEEP_SECOND = 120  # maximum time sleep time to wait with exp backoff
BUFFER = 100  # estimated tokens used by OpenAI + some more buffer
SYS_PROMPT = "You are Codex, a code completion language model. Continue the code presented to you."

# openai_api_key = os.environ.get("OPENAI_API_KEY")
# assert openai_api_key is not None, "Please set openai_api_key with your API key"
client = OpenAI(base_url=env_loader.INFERENCE_URL, api_key="None")


def query(
    args,
    prompt: str,
) -> ChatCompletion:
    """
    This function queries an OpenAI API to generate code based on the given prompt.

    Args:
    prompt: str, the prompt to generate code from
    temperature: float, the value used to module the next token probabilities
    max_tokens: int, the maximum number of tokens to generate
    top_p: float, the cumulative probability for top-p filtering

    Returns:
    OpenAI Completion object, the response from the OpenAI Codex API
    """
    if not args.model.startswith("o"):
        if not args.reasoning_model:
            return client.chat.completions.create(
                model=args.model,
                messages=[
                    {"role": "system", "content": SYS_PROMPT},
                    {"role": "user", "content": prompt},
                ],
                temperature=args.temperature,
                max_tokens=args.generation_max_tokens,
                top_p=args.top_p,
                stop=["[/ANSWER]"],
            )
        elif args.model.startswith("Qwen/QwQ"):
            # Based on QwQ recommended settings - https://huggingface.co/Qwen/QwQ-32B#usage-guidelines
            return client.chat.completions.create(
                model=args.model,
                messages=[
                    {"role": "system", "content": SYS_PROMPT},
                    {"role": "user", "content": prompt},
                ],
                temperature=0.6,
                max_tokens=args.generation_max_tokens,
                top_p=0.95,
                # stop=["[/ANSWER]"],
            )
    else:
        return client.chat.completions.create(
            model=args.model,
            messages=[
                {"role": "developer", "content": SYS_PROMPT},
                {"role": "user", "content": prompt},
            ],
            temperature=args.temperature,
            max_completion_tokens=25000,
            reasoning_effort="high",
        )


def query_with_retry(
    args,
    prompt: str,
) -> ChatCompletion | None:
    """
    This function queries an OpenAI API to generate code based on the given prompt.

    Args:
    prompt: str, the prompt to generate code from
    sleep_second: int, the number of seconds to sleep when the rate limit error is raised
    temperature: float, the value used to module the next token probabilities
    max_tokens: int, the maximum number of tokens to generate
    top_p: float, the cumulative probability for top-p filtering

    Returns:
    OpenAI Completion object, the response from the OpenAI Codex API if succeeds
    else return None

    Reference:
    https://github.com/Leolty/repobench/blob/c24b7a80465957e75107eafd23c66d369fa9e755/model/codex.py
    """

    error_sleep_second = SLEEP_SECOND

    def _upd_error_sleep_time(error_sleep_second):
        # double the sleep time if it is less than MAX_SLEEP_SECOND seconds
        if error_sleep_second < MAX_SLEEP_SECOND:
            error_sleep_second *= 2
        # if the sleep time is greater than MAX_SLEEP_SECOND seconds,
        # then sleep MAX_SLEEP_SECOND seconds
        else:
            error_sleep_second = MAX_SLEEP_SECOND
        return error_sleep_second

    while True:
        try:
            response = query(args, prompt)
            time.sleep(SLEEP_SECOND + np.random.rand())
            return response
        except openai.RateLimitError as e:
            print(f"RateLimitError: {e}")
            print(f"Retrying after {error_sleep_second} seconds")
            time.sleep(error_sleep_second)
            error_sleep_second = _upd_error_sleep_time(error_sleep_second)
        except openai.OpenAIError as e:
            print(f"OpenAIError: {e}")
            print(f"Retrying after {error_sleep_second} seconds")
            time.sleep(error_sleep_second)
            error_sleep_second = _upd_error_sleep_time(error_sleep_second)


def truncate(prompt: str, max_num_tokens: int, tokenizer, side: str) -> str:
    """Truncate prompt from side given the token budget"""

    # use tiktokenizer to analyze num of tokens
    tokens = tokenizer.encode(prompt, disallowed_special=())
    num_tokens = len(tokens)

    if num_tokens > max_num_tokens:
        if side == "left":
            prompt_tokens = tokens[num_tokens - max_num_tokens :]
        elif side == "right":
            prompt_tokens = tokens[:max_num_tokens]
        else:
            assert False, "Invalid side"
        # decode and encode again as a sanity check
        prompt = tokenizer.decode(prompt_tokens)
        new_len = len(tokenizer.encode(prompt, disallowed_special=()))
        assert (
            new_len <= max_num_tokens
        ), f"New length: {new_len}, Max tokens: {max_num_tokens}"
    return prompt


def prepare_prompt(
    prompt: str,
    cross_file_context: str,
    cross_file_budget: int,
    prompt_budget: int,
    tokenizer,
    is_reasoning: bool = False,
) -> str:
    """Create an augmented prompt according to budget specs"""

    # left truncate original prompt
    prompt = truncate(prompt, prompt_budget, tokenizer, "left")

    if cross_file_context is not None:
        # right truncate cross file context string
        cross_file_context = truncate(
            cross_file_context, cross_file_budget, tokenizer, "right"
        )
    else:
        cross_file_context = ""
    
    prompt = (
        cross_file_context
        + "\n"
        + prompt
        + "\n\n"
        + "Complete the last line of the above code. Do not generate multiple lines. Do not send the whole line again, just the missing part. Do not generate any other text."
    )

    return prompt


def get_openai_response(sample: Dict, tokenizer, args) -> Tuple[str, Dict]:
    """Get OpenAI response for a single sample. Returns the prompt used to
    infer and the response of the API."""
    if args.use_crossfile_context:
        prompt = prepare_prompt(
            sample["prompt"],
            sample["crossfile_context"]["text"],
            args.crossfile_max_tokens,
            args.model_max_tokens
            - args.generation_max_tokens
            - args.crossfile_max_tokens
            - BUFFER,
            tokenizer,
            args.reasoning_model,
        )
    else:
        prompt = prepare_prompt(
            sample["prompt"],
            None,
            0,
            args.model_max_tokens - args.generation_max_tokens - BUFFER,
            tokenizer,
            args.reasoning_model,
        )
    if not args.perturbator:
        response = query_with_retry(args, prompt)
    else:
        response = args.perturbator.query(prompt)


    return prompt, response


def get_openai_responses(args, data):
    """Get OpenAI responses to all samples in data, store in out_path,
    and return list of task ids that were skipped due to some errors"""
    tokenizer = tiktoken.get_encoding("o200k_base")
    skipped = []
    data_to_write = []
    # with open(out_path, "w") as f:
    for d in tqdm(data):
        try:
            try:
                prompt, response = get_openai_response(d, tokenizer, args)
            except Exception as e:
                print("Unknown error", e)
                raise

            if response is not None:
                if isinstance(response, str):
                    # MAD response
                    d["pred_raw"] = response
                else:
                    d["pred_raw"] = response.choices[
                        0
                    ].message.content  # key compatible with eval script

                print("Groundtruth:", d["groundtruth"])
                # print("Raw prediction:", d["pred_raw"])

                ans = d["pred_raw"] if d["pred_raw"] != "ERROR" else ""

                if args.reasoning_model and args.model.startswith("Qwen/QwQ"):
                    idx = ans.find("</think>")
                    if idx != -1:
                        ans = ans[idx + 8 :]
                    else:
                        ans = ""
                        print("Ran out of tokens")


                ans = ans.strip()
                ans = ans.split("\n")[0].strip()
                d["pred"] = ans
                print("Prediction:", d["pred"])

                # else:
                #     d["pred"] = (
                #         "\n".join(d["pred_raw"].split("\n")[1:]).strip("`")
                #         if d["pred_raw"].startswith("```")
                #         else d["pred_raw"]
                #     )  # newer chatgpt may ourput ```[lang_tag]``` at beginning

                # d['api_response'] = str(response)
                d["prompt_used"] = prompt  # records the augmented prompt
                d["task_id"] = d["metadata"][
                    "task_id"
                ]  # adding for compatibility with eval script
                data_to_write.append(d)
                # print(json.dumps(d), file=f, flush=True)
            else:
                skipped.append(d["metadata"]["task_id"])
                print(f'Skipped {d["metadata"]["task_id"]}')
        except KeyboardInterrupt:
            print("Stopping due to keyboard interrupt")
            break

    return data_to_write, skipped


def main():
    # get config for current run
    parser = argparse.ArgumentParser()
    parser.add_argument("--temperature", type=float, default=0.0)
    parser.add_argument("--top_p", type=float, default=0.95)
    parser.add_argument(
        "--task",
        type=str,
        required=True,
    )
    parser.add_argument(
        "--language",
        type=str,
        required=True,
        choices=["csharp", "python", "java", "typescript"],
    )
    parser.add_argument(
        "--data_root_dir",
        type=str,
        default="data/",
        help="path to directory where data is organized in lang/task.jsonl format",
    )
    parser.add_argument(
        "--output_dir",
        type=str,
        required=True,
        help="path to directory where to store outputs",
    )
    parser.add_argument(
        "--model", type=str, required=True, help="openAI-supported model"
    )
    parser.add_argument(
        "--model_max_tokens",
        type=int,
        default=17000,
        help="maximum number of tokens of the model",
    )
    parser.add_argument(
        "--crossfile_max_tokens",
        type=int,
        default=12800,
        help="maximum number of tokens for cross file context",
    )
    parser.add_argument(
        "--use_crossfile_context",
        action="store_true",
        help="whether use cross file context",
    )
    parser.add_argument(
        "--generation_max_tokens",
        type=int,
        default=50,
        help="maximum number of tokens to generate",
    )
    parser.add_argument("--reasoning-model", action="store_true")
    parser.add_argument(
        "--concept",
        type=str,
    )
    parser.add_argument(
        '--perturbation',
        type=str,
    )        
    args = parser.parse_args()
    print(json.dumps(vars(args), indent=4))

    if args.concept is not None:
        args.perturbator = Perturbator(
            args.model, args.concept, args.perturbation, max_length=args.model_max_tokens
        )
    else:
        args.perturbator = None
        

    if args.reasoning_model:
        args.model_max_tokens = 25000
        args.generation_max_tokens = 8000
    else:
        args.model_max_tokens = 25000
        args.generation_max_tokens = 1024

    global client

    if args.model.startswith("o"):
        client = OpenAI()


    output_dir = Path(args.output_dir)
    # setup paths
    if not output_dir.is_dir():
        print(f"==== Output dir does not exist. Creating: {args.output_dir} ====")
        output_dir.mkdir(parents=True, exist_ok=True)

    if not args.concept or args.perturbation == 'comment':
        data_path = os.path.join(
            args.data_root_dir, args.language, "sample", args.task + ".jsonl"
        )
    else:
        data_path = os.path.join(
            args.data_root_dir,
            args.language,
            "sample",
            f"{args.concept}_commented.jsonl",
        )
    data = [json.loads(l) for l in open(data_path, "r").readlines()]

    print(f"==== Number of tasks: {len(data)} ====")
    data = [d for d in data if "prompt" in d and "crossfile_context" in d]

    # data = get_sample(data)
    out_path = os.path.join(args.output_dir, "direct.jsonl")


    # start OpenAI inference
    data_to_write, skipped_tasks = get_openai_responses(args, data)

    with jsonlines.open(out_path, "w") as f:
        f.write_all(data_to_write)

    # save list of skipped tasks
    with jsonlines.open(out_path.replace(".jsonl", "_skipped_tasks.json"), "w") as f:
        f.write_all(skipped_tasks)


if __name__ == "__main__":
    main()
