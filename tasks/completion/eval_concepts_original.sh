#!/bin/bash
usage() {
    echo "Usage: $0 -m model"
    echo "Options:"
    echo "  -m model      Model name"
    exit 1
}
# Parse command-line arguments
while getopts "m:p:" opt; do
    case "$opt" in
        m) model="$OPTARG" ;; 
        p) perturbation="$OPTARG" ;;
        *) usage ;;
    esac
done

export model="$model"
export language="java"
if [[ $perturbation == "uncomment" ]]; then
    export experiment="both_commented"
else
    export experiment="both_comments_removed"
fi
export prompt_file=./data/${language}/sample/${experiment}\.jsonl
export output_dir=./tmp/$(basename "$model")/${language}/${experiment}/
export ts_lib=./build/java-lang-parser.so;


concepts=("javadoc" "inline" "multiline")

source /home/alirezi/miniconda3/etc/profile.d/conda.sh
conda activate r-eval

for concept in "${concepts[@]}"; do
    python scripts/eval.py --prompt_file $prompt_file --output_dir $output_dir --ts_lib $ts_lib --language $language --only_compute_metric --prompt direct --collect-ids-from-file ./data/java/sample/${concept}_commented.jsonl
done