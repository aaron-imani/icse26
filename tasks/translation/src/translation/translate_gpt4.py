import argparse
import logging
import os
import re
from pathlib import Path

# from dotenv import load_dotenv
from openai import OpenAI
from tqdm import tqdm
from rq2.tcav.perturbator import Perturbator
from common import env_loader
from common.cot import CoTAgent
from common.MAD.interactive import call_mad

base_url = env_loader.INFERENCE_URL
model_name = env_loader.MODEL_NAME
client = OpenAI(base_url=base_url, api_key="None")

os.makedirs(f"logs", exist_ok=True)
logging.basicConfig(
    filename=f"logs/translation.log",
    level=logging.INFO,
    format="%(asctime)s %(levelname)s %(module)s - %(funcName)s: %(message)s",
    datefmt="%Y-%m-%d %H:%M:%S",
)


class Translate:
    EXTENSTIONS = {
        "Java": "java",
        "Python": "py",
        "Go": "go",
        "C": "c",
        "C++": "cpp",
        "Rust": "rs",
        "C#": "cs",
    }

    def __init__(self, dataset, prompt, perturbation, concept) -> None:
        # Set up OpenAI API key
        self.model = model_name
        self.dataset = dataset
        self.prompt = prompt
        self.concept = concept
        self.perturbation = perturbation

        if self.prompt == "cot":
            self.cot_agent = CoTAgent(
                task="Given a source code to translate from FROM to TO language, output the translated code without any introduction and end the code with the comment 'End of Code'.",
                max_tokens=8000,
                default_answer="",
            )
        if perturbation is not None:
            self.perturbator = Perturbator(
                model_name=self.model,
                concept=self.concept,
                mode=perturbation,
                max_length=8000 if "QwQ" not in model_name else 25000,
            )
        else:
            self.perturbator = None

    def __enter__(self):
        # api_key = os.getenv("OPENAI_API_KEY")
        # openai.api_key = api_key
        # logging.info(f"successfully set up openai api key")

        self.main_dir = os.getcwd()
        self.output_dir = os.path.join(self.main_dir, "output")

        # Find the input directory with all the code examples
        self.input_dir = Path(self.main_dir).joinpath("filtered_dataset", self.dataset)

        self.hf_cache_dir = os.path.join(self.main_dir, "hf_cache_dir")

        if not self.input_dir.exists():
            logging.error(
                f"directory {str(self.input_dir)} does not exist. raising FileNotFoundError"
            )
            raise FileNotFoundError(f"Directory {str(self.input_dir)} does not exist.")

        if not self.perturbator:
            self.out_dir = Path(self.output_dir).joinpath(self.model, self.dataset)
            if not self.out_dir.exists():
                self.out_dir.mkdir(parents=True)
        else:
            self.out_dir = Path(self.output_dir).joinpath(
                self.model, self.dataset, self.prompt, self.concept, self.perturbation
            )
            if not self.out_dir.exists():
                self.out_dir.mkdir(parents=True, exist_ok=True)

        return self

    def send_message_to_openai(self, message_log):
        "Use OpenAI's ChatCompletion API to get the chatbot's response"
        # encoding = tiktoken.encoding_for_model("gpt-4")
        # num_tokens = len(encoding.encode(message_log[1]["content"]))

        response = "exceptional case"
        # is_success = False
        # max_attempts = 5
        # while max_attempts > 0:
        #     try:
        if "QwQ" not in model_name:
            response = client.chat.completions.create(
                model=model_name,  # The name of the OpenAI chatbot model to use
                # The conversation history up to this point, as a list of dictionaries
                messages=message_log,
                # The maximum number of tokens (words or subwords) in the generated response
                # max_tokens=max(1, 8000 - num_tokens),
                max_tokens=8000,
                # The "creativity" of the generated response (higher temperature = more creative)
                temperature=0.0,
            )
        else:
            response = client.chat.completions.create(
                model=model_name,  # The name of the OpenAI chatbot model to use
                # The conversation history up to this point, as a list of dictionaries
                messages=message_log,
                # The maximum number of tokens (words or subwords) in the generated response
                # max_tokens=max(1, 8000 - num_tokens),
                max_tokens=25000,
                # The "creativity" of the generated response (higher temperature = more creative)
                temperature=0.6,
                top_p=0.95,
            )
            if "</think>" not in response.choices[0].message.content:
                return "# Token size exceeded."
            return response.choices[0].message.content.split("</think>")[1]

        if "End of Code" not in response.choices[0].message.content:
            return "# Token size exceeded."

        #         is_success = True
        #         break
        #     except openai.error.InvalidRequestError as e:
        #         return "# Token size exceeded."
        #     except:
        #         max_attempts -= 1
        #         continue

        # if not is_success:
        #     return response

        # # Find the first response from the chatbot that has text in it (some responses may not have text)
        # for choice in response.choices:
        #     if "text" in choice:
        #         return choice.text

        # If no response with text is found, return the first response's content (which may be empty)
        return response.choices[0].message.content

    def translate_with_OPENAI(self, source, code_as_str, to):
        content = (
            code_as_str
            + f'\n\nTranslate the above {source} code to {to}. Output only the {to} code without any introduction and end the code with the comment "End of Code".\n'
        )

        if self.prompt == "direct":
            message = [
                {"role": "system", "content": "You are a helpful assistant."},
                {"role": "user", "content": content},
            ]
            if not self.perturbator:
                response = self.send_message_to_openai(message)
            else:
                response = self.perturbator.query(content)
                if "QwQ" in model_name:
                    if "</think>" not in response:
                        response = "# Token size exceeded."
                    else:
                        response = response.split("</think>")[1]
        elif self.prompt == "cot":
            content = f"FROM: {source}\n" f"TO: {to}\n\n" f"{code_as_str}"
            response = self.cot_agent.invoke(content)
        elif self.prompt == "mad":
            response = call_mad(content)

        language_tag = to.lower() if to != "C++" else "cpp"
        return re.sub(rf"`{{3}}{language_tag}|`{{3}}\s*", "", response).strip()

    def translate(self, source, target):
        snippets = list(self.input_dir.joinpath(str(source), "Code").iterdir())
            
        if self.perturbation == 'uncomment':
            import json
            with open('codenet_comment_splits.json', 'r') as f:
                comment_splits = json.load(f)
            
            snippets = [
                snippet
                for snippet in snippets
                if snippet.name in comment_splits[self.concept]
            ]
        elif self.perturbation == 'comment':
            snippets = [
                snippet
                for snippet in snippets
                if 'comments_removed' not in snippet.name
            ]

        progress_bar = tqdm(
            snippets,
            total=len(snippets),
            colour="green",
            leave=False,
            unit="files",
            desc=f"Translating to {target}",
        )

        for source_file in progress_bar:
            code_id = source_file.stem
            progress_bar.set_postfix({"file": code_id})

            code_as_str = source_file.read_text(encoding="utf-8")

            target_dir = self.out_dir.joinpath(self.prompt, f"{source}", f"{target}")
            if not target_dir.exists():
                target_dir.mkdir(parents=True)

            filename_of_translated_code = target_dir.joinpath(
                f"{code_id}.{Translate.EXTENSTIONS[target]}"
            )

            translated_code_fp = Path(filename_of_translated_code)
            if translated_code_fp.exists():
                tqdm.write(f"File {translated_code_fp} already exists. Skipping translation for {code_id}.")
                continue

            translated_code = self.translate_with_OPENAI(source, code_as_str, target)
            translated_code = re.sub(
                "public\s*class\s*.+", "public class " + code_id + " {", translated_code
            )

            if self.dataset == "evalplus" and target == "Java":
                translated_code = "package com.example;\n" + translated_code

            with open(filename_of_translated_code, "w") as f:
                print(translated_code, file=f)

    def __exit__(self, exception, _, __):
        if exception is None:
            print("Translation completed successfully.")
        else:
            print("Translation failed.")
            print(exception)


if __name__ == "__main__":

    # load_dotenv()

    parser = argparse.ArgumentParser(
        description="run translation with GPT-4 with a given dataset and languages"
    )
    parser.add_argument(
        "--dataset",
        help="dataset to use for code translation. should be one of [codenet,avatar,evalplus]",
        required=True,
        type=str,
    )
    parser.add_argument(
        "-m",
        "--model_name",
        help="model name to use for code translation"
    )

    parser.add_argument(
        "--source_lang",
        help="source language to use for code translation. should be one of [Python,Java,C,C++,Go]",
        required=True,
        type=str,
    )
    parser.add_argument(
        "--target_lang",
        help="target language to use for code translation. should be one of [Python,Java,C,C++,Go]",
        required=True,
        type=str,
    )
    parser.add_argument(
        "--k",
        help="The number of highest probability vocabulary tokens to keep for top-k-filtering. Only applies for sampling mode, with range from 1 to 100.",
        required=True,
        type=int,
    )
    parser.add_argument(
        "--p",
        help="Only the most probable tokens with probabilities that add up to top_p or higher are considered during decoding. The valid range is 0.0 to 1.0. 1.0 is equivalent to disabled and is the default. Only applies to sampling mode. Also known as nucleus sampling.",
        required=True,
        type=float,
    )
    parser.add_argument(
        "--temperature",
        help='A value used to warp next-token probabilities in sampling mode. Values less than 1.0 sharpen the probability distribution, resulting in "less random" output. Values greater than 1.0 flatten the probability distribution, resulting in "more random" output. A value of 1.0 has no effect and is the default. The allowed range is 0.0 to 2.0.',
        required=True,
        type=float,
    )
    parser.add_argument(
        "--prompt",
        required=True,
        type=str,
    )
    parser.add_argument(
        '--perturbation',
        default=None,
        type=str,
        help='Whether to use perturbation for translation. If set, the translation will be perturbed.',
    ) 
    parser.add_argument(
        '--concept',
        default=None,
        type=str,
        help='The concept to use for perturbation. If set, the translation will be perturbed.',
    ) 
    args = parser.parse_args()

    model_name = args.model_name if args.model_name else model_name
    source = args.source_lang
    target = args.target_lang
    with Translate(args.dataset, args.prompt, args.perturbation, args.concept) as translator:
        logging.info(
            f"translating examples from {source} to {target} using {model_name} and {args.dataset} dataset"
        )
        translator.translate(source, target)
