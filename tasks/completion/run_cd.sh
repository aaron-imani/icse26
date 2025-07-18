#!/bin/bash
usage() {
    echo "Usage: $0 -m model -l language -e experiment"
    echo "Options:"
    echo "  -m model      Model name"
    echo "  -r            Enable reasoning"
    exit 1
}
reasoning=""
# Parse command-line arguments
while getopts "rm:d:c:" opt; do
    case "$opt" in
        m) model="$OPTARG" ;; 
        d) device="$OPTARG" ;;
        c) concepts=("$OPTARG") ;;
        r) reasoning="-r" ;;
        *) usage ;;
    esac
done

# echo "Available CUDA devices: $(nvidia-smi --query-gpu=name --format=csv,noheader)"

if [[ ! -z "$device" ]]; then
    export CUDA_VISIBLE_DEVICES="$device"
    echo "Using CUDA device: $device"
fi

perturbation="uncomment"
if [[ -z "$concepts" ]]; then
    concepts=("comment" "javadoc" "inline" "multiline")
fi

echo "Concepts: ${concepts[*]}"

for concept in "${concepts[@]}"; do
    ./run_experiment_new.sh -m "$model" -l "java" -e "both_commented" -p direct -c "$concept" -t "$perturbation" "$reasoning" 
done

# ./eval_concepts_original.sh -m "$model"