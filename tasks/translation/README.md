# Code Translation

We replicated the experiments from the paper [_Lost in Translation: A Study of Bugs Introduced by Large Language Models while Translating Code_](http://arxiv.org/abs/2308.03109) to evaluate the performance of various LLMs on code translation tasks.

## Dataset

We downloaded the dataset used in the paper from [Zenodo](https://zenodo.org/doi/10.5281/zenodo.8190051). The dataset is organized as follows:

1. [CodeNet](https://github.com/IBM/Project_CodeNet)
2. [AVATAR](https://github.com/wasiahmad/AVATAR)
3. [Evalplus](https://github.com/evalplus/evalplus)
4. [Apache Commons-CLI](https://github.com/apache/commons-cli)
5. [Click](https://github.com/pallets/click)

After downloading and unzipping the `dataset.zip` file from Zenodo, you should see the following directory structure:

```
PLTranslationEmpirical
├── dataset
    ├── codenet
    ├── avatar
    ├── evalplus
    ├── real-life-cli
├── ...
```

We then filtered the dataset using the following command to get commented records:

```bash
python filter_dataset.py
```

Then, we split the dataset into comment types, i.e., `javadoc`, `inline`, and `multiline`, using the following command:

```bash
python make_rq2_split.py
```
## RQ3

Run the following command to generate the baseline results:

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