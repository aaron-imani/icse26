#!/bin/bash
model_name=$1

./eval.sh Qwen/$model_name direct comment uncomment
./eval.sh Qwen/$model_name direct javadoc uncomment
./eval.sh Qwen/$model_name direct inline uncomment
./eval.sh Qwen/$model_name direct multiline uncomment
