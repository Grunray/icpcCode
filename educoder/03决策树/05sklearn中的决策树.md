# 05sklearn中的决策树

## 题目核心点
- 题目说什么：用 sklearn 的 `DecisionTreeClassifier` 完成鸢尾花分类任务，返回测试集预测标签。
- 要我做什么：在 `iris_predict(train_sample, train_label, test_sample)` 中训练决策树并输出预测结果。
- 解决方法是什么：遵循 sklearn 监督学习通用流程（实例化 → fit → predict），使用基尼系数划分并限制树深提高稳定准确率。

## 方法与步骤
- 模型：`DecisionTreeClassifier(criterion='gini', splitter='best', max_depth=3, random_state=0)`。
- 训练：`clf.fit(train_sample, train_label)`。
- 预测：`clf.predict(test_sample)`。
- 设计取舍：
  - `gini`（基尼系数）在鸢尾花上通常泛化较好；
  - `max_depth=3` 抑制过拟合，兼顾精度与稳定性；
  - 固定 `random_state=0` 以提升复现性与一致性。

## 复杂度
- 训练复杂度与树深、样本数、特征数相关，近似 `O(N M)`（实际优于线性常数项）。
- 预测复杂度为单样本路径深度，近似 `O(depth)`。

## 说明
- 若准确率仍不足，可在平台侧微调：`max_depth`（2/4）、`min_samples_leaf`（2）、`min_samples_split`（4），保持 `splitter='best'`。
- 按参考文章流程，数据加载与划分由平台完成；本函数仅负责训练与预测。