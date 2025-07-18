#!/bin/bash
usage() {
    echo "Usage: $0 -m model -l language -e experiment"
    echo "Options:"
    echo "  -m model      Model name"
    echo "  -p prompt     Prompt type ('direct' or 'cot')"
    echo "  -r            Enable reasoning"
    exit 1
}
reasoning=false
prompt=direct

# Parse command-line arguments
while getopts "m:l:e:p:r" opt; do
    case "$opt" in
        m) model="$OPTARG" ;;
        p) prompt="$OPTARG" ;;
        r) reasoning=true ;;
        *) usage ;;
    esac
done

languages=("java")


experiment="both_comments_removed"

# Print task info
echo "Experiment: $experiment"
if [ "$reasoning" = true ]; then
    ./run_experiment_new.sh -m "$model" -l java -e "$experiment" -p "$prompt" -r
else
    ./run_experiment_new.sh -m "$model" -l java -e "$experiment" -p "$prompt"
fi

context_experiments=("both")
experiments=("commented")

for language in "${languages[@]}"; do
    for context_experiment in "${context_experiments[@]}"; do
        for crossfile_context_experiment in "${experiments[@]}"; do
            experiment="${context_experiment}_${crossfile_context_experiment}"

            # Print task info
            echo "Experiment: $experiment"
            if [ "$reasoning" = true ]; then
                ./run_experiment_new.sh -m "$model" -l "$language" -e "$experiment" -p "$prompt" -r
            else
                ./run_experiment_new.sh -m "$model" -l "$language" -e "$experiment" -p "$prompt"
            fi
        done
    done
done

