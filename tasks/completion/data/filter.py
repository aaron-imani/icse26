import os
import re
import sys
from copy import deepcopy
from pathlib import Path

from jsonlines import jsonlines
from termcolor import colored

from comment_removal.java_comment_remover import has_comment as java_has_comment
from comment_removal.java_comment_remover import remove_comments as java_remove_comments
from comment_removal.py_comment_remover import has_comment as python_has_comment
from comment_removal.py_comment_remover import remove_comments as python_remove_comments

curdir = Path(__file__).parent.resolve()
language = "java"
filename = "line_completion_rg1_bm25.jsonl"


java_snippet_pattern = re.compile(
    r"(?s)// the below code fragment can be found in:\n"  # Marker line
    r"//.*?\n"  # Skip file path line
    r"(.*?)"  # Capture everything after that ...
    r"(?=// the below code fragment can be found in:|$)"  # ... until next marker or end of text
)
python_snippet_pattern = re.compile(
    r"(?s)# the below code fragment can be found in:\n"  # Marker line
    r"#.*?\n"  # Skip file path line
    r"(.*?)"  # Capture everything after that ...
    r"(?=# the below code fragment can be found in:|$)"  # ... until next marker or end of text
)


def does_record_have_comment(record, has_comment, snippet_pattern):
    if has_comment(record["prompt"]):
        return True

    context = record["crossfile_context"]["text"]

    snippets = snippet_pattern.findall(context)
    indent = 2 if snippet_pattern == java_snippet_pattern else 1
    for snippet in snippets:
        lines = [line[indent:] for line in snippet.split("\n")]
        lines = "\n".join(lines)
        try:
            if has_comment(lines):
                return True
        except ValueError:
            # print("Broken comments detected in context. Skipping record.")
            # print(colored(lines, "red"))
            raise

    return False


def remove_comments_from_context(
    context, remove_comments, has_comments, snippet_pattern
):
    snippets = snippet_pattern.findall(context)

    indent = 2 if snippet_pattern == java_snippet_pattern else 1
    for snippet in snippets:
        # print(snippet, end="\n" + "--" * 20 + "\n")
        lines = [line[indent:] for line in snippet.split("\n")]
        lines = "\n".join(lines).rstrip()

        try:
            commented_removed = remove_comments(lines)
            # if has_comments(lines):
            #     print(lines, end="\n" + "--" * 20 + "\n")
            #     print(colored(commented_removed, "green"), end="\n" + "--" * 20 + "\n")
        except ValueError:
            print("Broken comments detected in context. Skipping record.")
            print(colored(lines, "red"))
            raise
        context = context.replace(snippet, commented_removed + "\n\n")

    return context


def filter_dataset(
    language, has_comments_method, remove_comments_method, snippet_pattern
):
    commented = []
    not_commented = []
    comments_removed = []
    total = 0
    with jsonlines.open(curdir / language / filename) as reader:
        for obj in reader:
            total += 1
            try:
                has_comments = does_record_have_comment(
                    obj, has_comments_method, snippet_pattern
                )
            except ValueError:
                continue

            if has_comments:
                cleaned_obj = deepcopy(obj)
                try:
                    cleaned_obj["prompt"] = remove_comments_method(
                        cleaned_obj["prompt"]
                    )
                except ValueError:
                    print(
                        f"Broken comments detected in {language} snippet. Skipping record."
                    )
                    print(colored(cleaned_obj["prompt"], "red"))
                    continue

                try:
                    cleaned_obj["crossfile_context"]["text"] = (
                        remove_comments_from_context(
                            cleaned_obj["crossfile_context"]["text"],
                            remove_comments_method,
                            has_comments_method,
                            snippet_pattern,
                        )
                    )
                except ValueError:
                    continue

                commented.append(obj)
                comments_removed.append(cleaned_obj)
            else:
                not_commented.append(obj)

    with jsonlines.open(
        curdir / language / f"line_completion_rg1_bm25_commented.jsonl", "w"
    ) as commented_writer:
        for obj in commented:
            commented_writer.write(obj)

    with jsonlines.open(
        curdir / language / f"line_completion_rg1_bm25_not_commented.jsonl", "w"
    ) as not_commented_writer:
        for obj in not_commented:
            not_commented_writer.write(obj)

    with jsonlines.open(
        curdir / language / f"line_completion_rg1_bm25_comments_removed.jsonl", "w"
    ) as comments_removed_writer:
        for obj in comments_removed:
            comments_removed_writer.write(obj)

    print(f"Total {language.capitalize()} records:", total)
    print(f"{language.capitalize()} records with comments:", len(commented))
    print(
        f"{language.capitalize()} records with comments removed:", len(comments_removed)
    )
    print(f"{language.capitalize()} records without comments:", len(not_commented))
    broken_count = total - len(commented)
    print(f"Records with broken comments:", broken_count)
    print("==" * 20)


if __name__ == "__main__":
    filter_dataset("java", java_has_comment, java_remove_comments, java_snippet_pattern)
    # filter_dataset(
    #     "python", python_has_comment, python_remove_comments, python_snippet_pattern
    # )
