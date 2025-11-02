# 03sklearn中的聚类性能评估指标 题解与实现说明

## 题目核心点
- 使用 sklearn 的接口评估聚类性能：`adjusted_rand_score`（调整 Rand 指数）与 `fowlkes_mallows_score`（FM 指数）。
- 输入为参考簇划分与聚类簇划分的一维列表或数组，返回两个指标值。

## 你要做什么
- 在 `03sklearn中的聚类性能评估指标.py` 中实现 `cluster_performance(y_true, y_pred)`。
- 函数需要按平台示例的顺序返回两个指标：先返回 `FM`，再返回 `调整 Rand (ARI)`。

## 解决方法
- 直接调用 sklearn 提供的两个函数，并将输入转换为列表以确保兼容：
  - `fm = fowlkes_mallows_score(y_true, y_pred)`
  - `ari = adjusted_rand_score(y_true, y_pred)`
- 按示例期望顺序返回：`return fm, ari`。

## 复杂度与特性
- 两个指标的计算由 sklearn 内部实现，时间复杂度取决于底层实现（一般为 `O(n)` 或 `O(n log n)`）。
- 接口健壮，支持 `list` 或一维 `ndarray` 输入。

## 示例测试
- 输入：
  - `y_true = [0, 0, 1, 1]`
  - `y_pred = [1, 0, 1, 1]`
- 期望输出：`FM = 0.408248`，`ARI = 0.000000`
- 对应调用：`cluster_performance(y_true, y_pred) -> (0.408248..., 0.0)`

## 关键实现片段（ACM-ICPC 风格）
```python
from sklearn.metrics.cluster import fowlkes_mallows_score, adjusted_rand_score

def cluster_performance(y_true, y_pred):
    yt = list(y_true); yp = list(y_pred)
    fm = float(fowlkes_mallows_score(yt, yp))
    ari = float(adjusted_rand_score(yt, yp))
    return fm, ari
```