import os
from pathlib import Path

from tqdm import tqdm

from comment_removal.nirjas import *
from common.utils import get_sample

cur_dir = Path(__file__).resolve().parent
dataset_path = cur_dir / "dataset"
filtered_dataset_path = cur_dir / "filtered_dataset"
filtered_dataset_path.mkdir(exist_ok=True)

# Avatar doesn't have comments, so we skip it
# The real-life-cli also doesn't have comments, so we skip it

# First, filter the codenet dataset
codenet_dataset_path = dataset_path / "codenet" / "Java" / "Code"
codenet_testcases_path = dataset_path / "codenet" / "Java" / "TestCases"

codenet_filtered_dataset_path = filtered_dataset_path / "codenet" / "Java"
codenet_filtered_dataset_path.mkdir(parents=True, exist_ok=True)
filtered_code_path = codenet_filtered_dataset_path / "Code"
filtered_code_path.mkdir(parents=True, exist_ok=True)
testcases_path = codenet_filtered_dataset_path / "TestCases"
testcases_path.mkdir(parents=True, exist_ok=True)

total = 0
commented = 0
commented_records = []

for f in tqdm(
    codenet_dataset_path.glob("*.java"),
    desc="Filtering codenet dataset",
):
    total += 1
    with open(f, "r", encoding="utf-8", errors="ignore") as input_file:
        content = input_file.read()

    comments_removed = remove_comments(content)
    if comments_removed.strip() != content.strip():
        commented += 1
        commented_records.append((f.stem, content, comments_removed))


print("Filtered codenet dataset")
print(f"Total: {total}, Commented: {commented}")
commented_records = get_sample(commented_records)
print(f"Sampled: {len(commented_records)}")

for name, content, comments_removed in tqdm(
    commented_records,
    desc="Writing codenet dataset",
):
    with open(
        filtered_code_path / f"{name}_comments_removed.java",
        "w",
        encoding="utf-8",
    ) as output_file:
        output_file.write(comments_removed)
    with open(
        filtered_code_path / f"{name}_commented.java", "w", encoding="utf-8"
    ) as output_file:
        output_file.write(content)
    # Copy the test cases
    for test_case in codenet_testcases_path.glob(f"{name}*.txt"):
        os.system(f"cp {test_case} {testcases_path / test_case.name}")
