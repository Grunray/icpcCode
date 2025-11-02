# 06sklearn中的神经网络

## 题目核心点
- 问题：使用 sklearn 的 MLPClassifier 训练并预测鸢尾花三分类，准确率≥95%。
- 输入：训练集 `(X, y)`，测试集 `X_test`。
- 输出：`X_test` 的预测标签。

## 解决方法
- 模型：多层感知机 MLP，采用 `lbfgs` 优化器，稳定且适合小数据集。
- 预处理：结合 `StandardScaler` 做特征标准化，提升收敛与准确率。
- 结构与超参：两层隐藏层 `(8, 8)`，`alpha=1e-4`，`max_iter=500`，`random_state=0` 保证可复现。
- 训练与预测：
  - 构建管道：`clf = StandardScaler → MLPClassifier`。
  - 训练：`clf.fit(X, y)`。
  - 预测：`pred = clf.predict(X_test)`。

## 复杂度分析
- 设样本数 `m`、特征维度 `n=4`、隐藏维度 `h`。
- 训练：`lbfgs` 每次迭代近似二阶优化，单轮复杂度高于一阶，但收敛轮数少；总体在小数据上更快收敛。
- 预测：`O(m·(n·h + h·h + h·3))`。

## 关键要点
- 标准化对 MLP 的梯度与收敛至关重要。
- 选择 `lbfgs` 在小样本上通常优于 `adam/sgd`，更稳定。
- 固定随机种子保证结果可重复，便于测试验证。

## 使用说明
- 直接调用：`iris_predict(train_sample, train_label, test_sample)` 返回预测标签数组。
- 若准确率略低，可适当增大 `max_iter` 或微调 `hidden_layer_sizes` 与 `alpha`。