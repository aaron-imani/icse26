import json
import os
from copy import deepcopy
from pathlib import Path
from typing import List

from jsonlines import jsonlines
from termcolor import colored

# from comment_removal.java_comment_remover import has_comment as java_has_comment
from comment_removal.nirjas import remove_comments as java_remove_comments

# from comment_removal.py_comment_remover import has_comment as python_has_comment
# from comment_removal.py_comment_remover import remove_comments as python_remove_comments
from common.utils import get_sample

curdir = Path(__file__).parent.resolve()
language = "java"
filename = "line_completion_rg1_bm25.jsonl"


def uncomment_context(
    chunks: List[str],
    remove_comments=None,
    return_both=False,
    return_commented_pairs=False,
):
    if return_both:
        original = (
            "Here are some relevant code fragments from other files of the repo:\n"
        )
        result = "Here are some relevant code fragments from other files of the repo:\n"

    if return_commented_pairs:
        pairs = []

    for chunk in chunks:
        result += "The below code fragment can be found in:\n"
        result += chunk["filename"] + "\n"

        if return_both:
            original += "The below code fragment can be found in:\n"
            original += chunk["filename"] + "\n"

        if not remove_comments:
            result += f"```java\n{chunk['retrieved_chunk']}\n```\n\n"
        else:
            try:
                cleaned_chunk = remove_comments(chunk["retrieved_chunk"])
                if return_both:
                    if cleaned_chunk.strip() == "":
                        raise ValueError("Empty code after comment removal")
                    original += f"```java\n{chunk['retrieved_chunk']}\n```\n\n"
                    result += f"```java\n{cleaned_chunk}\n```\n\n"
                else:
                    result += f"```java\n{cleaned_chunk}\n```\n\n"
            except ValueError:
                print("Broken comments detected in context. Skipping record.")
                print(colored(chunk["retrieved_chunk"], "red"))
                raise

            if cleaned_chunk != chunk["retrieved_chunk"] and return_commented_pairs:
                pairs.append((chunk["retrieved_chunk"], cleaned_chunk))

    if return_both:
        if return_commented_pairs:
            return original.rstrip(), result.rstrip(), pairs
        else:
            return original.rstrip(), result.rstrip()

    if return_commented_pairs:
        return result.rstrip(), pairs

    return result.rstrip()


def filter_dataset(language, remove_comments_method):
    experiments_data = {
        "both_commented": [],
        "both_comments_removed": [],
        "context_commented": [],
        "context_comments_removed": [],
        "prompt_commented": [],
        "prompt_comments_removed": [],
    }
    both_commented_records = []
    total = 0
    os.makedirs(curdir / language / "sample", exist_ok=True)

    with jsonlines.open(curdir / language / filename) as reader:
        for obj in reader:
            total += 1
            try:
                cleaned_prompt = remove_comments_method(obj["prompt"])
                revised_context, uncommented_context, context_pairs = uncomment_context(
                    obj["crossfile_context"]["list"],
                    remove_comments_method,
                    return_both=True,
                    return_commented_pairs=True,
                )

            except ValueError:
                print("Broken comments detected in context. Skipping record.")
                continue

            both_commented = (cleaned_prompt != obj["prompt"]) and len(
                context_pairs
            ) > 0
            if both_commented:
                obj["crossfile_context"]["text"] = revised_context
                obj["cleaned_prompt"] = cleaned_prompt
                obj["crossfile_context"]["cleaned_text"] = uncommented_context
                both_commented_records.append(obj)

            # elif comments_location == "Context":
            #     cleaned_obj = deepcopy(obj)
            #     try:
            #         cleaned_obj["crossfile_context"]["text"] = (
            #             remove_comments_from_context(
            #                 cleaned_obj["crossfile_context"]["text"],
            #                 remove_comments_method,
            #                 snippet_pattern,
            #             )
            #         )
            #     except ValueError:
            #         continue

            #     experiments_data["context_commented"].append(obj)
            #     experiments_data["context_comments_removed"].append(cleaned_obj)
            # elif comments_location == "Prompt":
            #     cleaned_obj = deepcopy(obj)
            #     try:
            #         cleaned_obj["prompt"] = remove_comments_method(
            #             cleaned_obj["prompt"]
            #         )
            #     except ValueError:
            #         print(
            #             f"Broken comments detected in {language} snippet. Skipping record."
            #         )
            #         print(colored(cleaned_obj["prompt"], "red"))
            #         continue

            #     experiments_data["prompt_commented"].append(obj)
            #     experiments_data["prompt_comments_removed"].append(cleaned_obj)

    sample = get_sample(both_commented_records)
    print(f"Total records: {total}")
    print(f"Records with comments: {len(both_commented_records)}")
    print(f"Sampled records: {len(sample)}")

    for obj in sample:
        both_cleaned = deepcopy(obj)
        both_cleaned["prompt"] = both_cleaned["cleaned_prompt"]
        both_cleaned["crossfile_context"]["text"] = both_cleaned["crossfile_context"][
            "cleaned_text"
        ]
        assert both_cleaned["metadata"]["task_id"] == obj["metadata"]["task_id"]

        experiments_data["both_commented"].append(obj)
        experiments_data["both_comments_removed"].append(both_cleaned)

        prompt_cleaned = deepcopy(obj)
        prompt_cleaned["prompt"] = prompt_cleaned["cleaned_prompt"]
        experiments_data["context_commented"].append(prompt_cleaned)
        experiments_data["context_comments_removed"].append(both_cleaned)
        assert (
            both_cleaned["metadata"]["task_id"] == prompt_cleaned["metadata"]["task_id"]
        )

        context_cleaned = deepcopy(obj)
        context_cleaned["crossfile_context"]["text"] = context_cleaned[
            "crossfile_context"
        ]["cleaned_text"]
        experiments_data["prompt_commented"].append(context_cleaned)
        experiments_data["prompt_comments_removed"].append(both_cleaned)
        assert (
            both_cleaned["metadata"]["task_id"]
            == context_cleaned["metadata"]["task_id"]
        )
    commented_task_ids = set(
        obj["metadata"]["task_id"] for obj in experiments_data["both_commented"]
    )
    removed_task_ids = set(
        obj["metadata"]["task_id"] for obj in experiments_data["both_comments_removed"]
    )
    assert (
        commented_task_ids.symmetric_difference(removed_task_ids) == set()
    ), "Task IDs do not match"

    commented_task_ids = set(
        obj["metadata"]["task_id"] for obj in experiments_data["context_commented"]
    )
    removed_task_ids = set(
        obj["metadata"]["task_id"]
        for obj in experiments_data["context_comments_removed"]
    )
    assert (
        commented_task_ids.symmetric_difference(removed_task_ids) == set()
    ), "Task IDs do not match"

    commented_task_ids = set(
        obj["metadata"]["task_id"] for obj in experiments_data["prompt_commented"]
    )
    removed_task_ids = set(
        obj["metadata"]["task_id"]
        for obj in experiments_data["prompt_comments_removed"]
    )
    assert (
        commented_task_ids.symmetric_difference(removed_task_ids) == set()
    ), "Task IDs do not match"

    for key, value in experiments_data.items():
        with open(curdir / language / "sample" / f"{key}.jsonl", "w") as f:
            for obj in value:
                f.write(json.dumps(obj) + "\n")


if __name__ == "__main__":
    filter_dataset("java", java_remove_comments)
    # filter_dataset(
    #     "python", python_has_comment, python_remove_comments, python_snippet_pattern
    # )
