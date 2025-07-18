model_name=$1
prompt=$2
concept=${3:-"none"}
perturbation=${4:-"none"}
split_results=${5:-"false"}

if [[ $# < 2 ]]; then
  exit 1;
fi

bash scripts/test_codenet.sh Java Python $model_name fix_reports 1 $prompt $concept $perturbation $split_results
bash scripts/test_codenet.sh Java C $model_name fix_reports 1 $prompt $concept $perturbation $split_results
bash scripts/test_codenet.sh Java C++ $model_name fix_reports 1 $prompt $concept $perturbation $split_results
bash scripts/test_codenet.sh Java Go $model_name fix_reports 1 $prompt $concept $perturbation $split_results