#!/bin/bash
model_name=$1

./eval.sh Qwen/$model_name direct comment comment
./eval.sh Qwen/$model_name direct javadoc comment
./eval.sh Qwen/$model_name direct inline comment
./eval.sh Qwen/$model_name direct multiline comment
