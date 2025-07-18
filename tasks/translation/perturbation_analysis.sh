#!/bin/bash

model=$1
concept=$2
perturbation=$3

bash scripts/translate.sh $model codenet Java Python 50 0.95 0.0 0 direct $concept $perturbation
bash scripts/translate.sh $model codenet Java C 50 0.95 0.0 0 direct $concept $perturbation
bash scripts/translate.sh $model codenet Java C++ 50 0.95 0.0 0 direct $concept $perturbation
bash scripts/translate.sh $model codenet Java Go 50 0.95 0.0 0 direct $concept $perturbation