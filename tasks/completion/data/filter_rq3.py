import json
import os
from copy import deepcopy
from pathlib import Path
from typing import List

from jsonlines import jsonlines
from termcolor import colored

# from comment_removal.java_comment_remover import has_comment as java_has_comment
from comment_removal.nirjas import get_comment_types

# from comment_removal.py_comment_remover import has_comment as python_has_comment
# from comment_removal.py_comment_remover import remove_comments as python_remove_comments
from common.utils import get_sample

curdir = Path(__file__).parent.resolve()
sample_file_path = curdir / "java" / "sample" / "both_commented.jsonl"

if not os.path.exists(sample_file_path):
    from filter import filter_dataset, java_has_comment, java_remove_comments, java_snippet_pattern
    filter_dataset("java", java_has_comment, java_remove_comments, java_snippet_pattern)

concepts = ["inline", "multiline", "comment", 'javadoc']
with jsonlines.open(sample_file_path, "r") as reader:
    sample = [item for item in reader]

    for concept in concepts:
        if concept == 'comment':
            concept_sample = sample
        else:
            concept_sample = []
            for item in sample:
                all_chunks_have_concept = False
                for chunk in item['crossfile_context']['list']:
                    if get_comment_types(chunk['retrieved_chunk'])[concept] == True:
                        all_chunks_have_concept = True
                        break
                
                if all_chunks_have_concept or get_comment_types(item['prompt'])[concept]:
                        concept_sample.append(item) 

        print(f"Number of samples with {concept} comments: {len(concept_sample)}")
        if concept_sample:
            with jsonlines.open(f"java/sample/{concept}_commented.jsonl", "w") as writer:
                writer.write_all(concept_sample)
        