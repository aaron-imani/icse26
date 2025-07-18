#!/bin/bash
usage() {
    echo "Usage: $0 -m model -l language -e experiment"
    echo "  -m model      Model name"
    echo "  -d device     CUDA device to use (optional)"
    echo "  -c concepts   Concepts to analyze (optional)"
    exit 1
}

while getopts "m:d:c:" opt; do
    case "$opt" in
        m) model="$OPTARG" ;; 
        d) device="$OPTARG" ;;
        c) concepts=("$OPTARG") ;;
        *) usage ;;
    esac
done

# echo "Available CUDA devices: $(nvidia-smi --query-gpu=name --format=csv,noheader)"

if [[ ! -z "$device" ]]; then
    export CUDA_VISIBLE_DEVICES="$device"
    echo "Using CUDA device: $device"
fi

if [[ -z "$concepts" ]]; then
    concepts=("comment" "javadoc" "inline" "multiline")
fi

for concept in "${concepts[@]}"; do
    ./perturbation_analysis.sh $model $concept comment
done

./eval_rq4.sh $(basename "$model")