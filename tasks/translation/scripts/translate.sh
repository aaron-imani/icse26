WORKDIR=`pwd`
export PYTHONPATH=$WORKDIR:$PYTHONPATH;
export PYTHONIOENCODING=utf-8;

function prompt() {
    echo;
    echo "Syntax: bash scripts/translate.sh MODEL DATASET SRC_LANG TRG_LANG K P TEMPERATURE GPU_ID";
    echo "MODEL: name of the model to use";
    echo "DATASET: name of the dataset to use";
    echo "SRC_LANG: source language";
    echo "TRG_LANG: target language";
    echo "K: top-k sampling";
    echo "P: top-p sampling";
    echo "TEMPERATURE: temperature for sampling";
    echo "GPU_ID: GPU to use";
    exit;
}

while getopts ":h" option; do
    case $option in
        h) # display help
          prompt;
    esac
done

# if [[ $# < 11 ]]; then
#   prompt;
# fi

MODEL=$1;
DATASET=$2;
SRC_LANG=$3;
TRG_LANG=$4;
K=$5;
P=$6;
TEMPERATURE=$7;
GPU_ID=$8;
PROMPT=$9;
CONCEPT=${10:-"none"};
PERTURBATION=${11:-"none"};
MODEL_NAME="-m $MODEL";

# if perturbation is not none, set the concept to the perturbation
if [[ $PERTURBATION != "none" ]]; then
  python -u src/translation/translate_gpt4.py --dataset $DATASET --source_lang $SRC_LANG --target_lang $TRG_LANG --k $K --p $P --temperature $TEMPERATURE --prompt $PROMPT --concept $CONCEPT --perturbation $PERTURBATION $MODEL_NAME;
else
  python -u src/translation/translate_gpt4.py --dataset $DATASET --source_lang $SRC_LANG --target_lang $TRG_LANG --k $K --p $P --temperature $TEMPERATURE --prompt $PROMPT;
fi  
# elif [[ $MODEL == "StarCoder" || $MODEL == "CodeGen" || $MODEL == "CodeGeeX" || $MODEL == "LLaMa" || $MODEL == "TB-Airoboros" || $MODEL == "TB-Vicuna" ]]; then
#   python3 src/translation/translate_open_source.py --model $MODEL --dataset $DATASET --source_lang $SRC_LANG --target_lang $TRG_LANG --k $K --p $P --temperature $TEMPERATURE --gpu_id $GPU_ID;
# else
#   echo "Model not supported";
# fi
