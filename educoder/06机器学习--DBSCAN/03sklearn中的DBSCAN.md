# 03sklearn中的DBSCAN

## 题目核心点
- 问题：使用 sklearn 的 DBSCAN 对非球状数据进行聚类。
- 输入：`data` 为形状 `[n_samples, n_features]` 的二维数组。
- 输出：簇标签数组，噪声为 `-1`。

## 解决方法
- 算法：密度聚类 DBSCAN（基于 `eps` 邻域与 `min_samples` 核心点判定）。
- 使用：`DBSCAN(eps=0.3, min_samples=5).fit_predict(data)` 返回每个样本的簇标签。
- 特性：无需指定簇数量，适配任意形状簇，对噪声点鲁棒。

## 复杂度
- 距离度量为欧氏距离，最坏情形近似 `O(n^2)`；
- 若使用空间索引（如 KDTree），可降至近似线性。

## 实现要点
- 仅训练并获取聚类结果，不做预测新样本；
- 参数选取针对 `make_moons` 非球状数据，保证簇连通且分离良好；
- 返回 `fit_predict` 的标签数组作为最终结果。