#!/bin/bash

# Usage function
usage() {
    echo "Usage: $0 -m model -l language -e experiment"
    echo "Options:"
    echo "  -m model      Model name"
    echo "  -l language   Language"
    echo "  -e experiment Experiment name ('commented' or 'comments_removed')"
    exit 1
}
prompt=direct

# Parse command-line arguments
while getopts "m:l:e:p:c:t:r" opt; do
    case "$opt" in
        m) model="$OPTARG" ;;
        l) language="$OPTARG" ;;
        e) experiment="$OPTARG" ;;
        p) prompt="$OPTARG" ;;
        c) concept="$OPTARG" ;;
        t) perturbation="$OPTARG" ;;
        r) reasoning="--reasoning-model" ;;
        *) usage ;;
    esac
done

echo "[DEBUG] model=$model, lang=$language, exp=$experiment, prompt=$prompt, concept=$concept, perturb=$perturbation, reasoning=$reasoning"
# Ensure all required variables are set
if [[ -z "$model" || -z "$language" || -z "$experiment" ]]; then
    echo "Error: All parameters must be provided!"
    usage
fi

echo "Model: $model"
echo "Language: $language"
echo "Experiment: $experiment"

# Export environment variables
export model
export language
export experiment

export ts_lib=./build/${language}-lang-parser.so;

source /home/alirezi/miniconda3/etc/profile.d/conda.sh
# Run Python scripts
if [[ -z "$concept" ]]; then
    export prompt_file=./data/${language}/sample/${experiment}\.jsonl
    export output_dir=./results/$(basename "$model")/${language}/${experiment}/
    conda activate ollm
else
    if [[ "$perturbation" == "uncomment" ]]; then
        export prompt_file=./data/${language}/sample/${concept}_commented.jsonl
    else
        export prompt_file=./data/${language}/sample/${experiment}\.jsonl
    fi
    export output_dir=./results/$(basename "$model")/${language}/${perturbation}/${concept}/
    conda activate torch-env
fi

python -u scripts/openai_inference.py --task $experiment --language $language --model $model --output_dir $output_dir --use_crossfile_context --prompt $prompt --concept $concept --perturbation $perturbation $reasoning

conda activate r-eval
python scripts/eval.py --prompt_file $prompt_file --output_dir $output_dir --ts_lib $ts_lib --language $language --only_compute_metric --prompt $prompt