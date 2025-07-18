# Code Completion Task

The data and inference code are adopted from the NeurIPS 2023  (Datasets and Benchmarks track) paper "[CrossCodeEval: A Diverse and Multilingual Benchmark for Cross-File Code Completion](https://arxiv.org/abs/2310.11248)."


## RQ3 

To generate baseline results, run the following command:

```bash
chmod +x run_baseline.sh
./run_baseline.sh
```

To run the experiments for RQ3, use the following command for each LLM:

```bash
chmod +x run_cd.sh
chmod +x run_ca.sh
./run_cd.sh -m <model-name>
./run_ca.sh -m <model-name>
```

where `<model-name>` can be one of the following: 

- `Qwen/Qwen2.5-Coder-32B-Instruct-AWQ`
- `Qwen/Qwen2.5-32B-Instruct-AWQ`
- `Qwen/QwQ-32B-AWQ`