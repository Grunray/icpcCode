#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>
using namespace std;

// 定义最小堆节点结构
struct MinHeapNode {
    // 当前路径的费用下界（lcost = cc + rcost）
    int minCost;
    // 当前路径的实际费用（已走过的路径费用）
    int nowCost;
    // 剩余顶点的最小出边费用和
    int otherCost;
    // 当前路径的长度（已访问的城市数量）
    int now;
    // 当前路径（存储城市编号）
    vector<int> nowPath;

    // 重载运算符，让优先队列按 lcost 从小到大排序
    bool operator<(const MinHeapNode& other) const {
        return minCost > other.minCost;
    }
};

// 计算每个顶点的最小出边费用
vector<int> computeMinOut(const vector<vector<int>>& adj, int n) {
    vector<int> minOutOfNode(n, INT_MAX);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i != j && adj[i][j] < minOutOfNode[i]) {
                minOutOfNode[i] = adj[i][j];
            }
        }
    }
    return minOutOfNode;
}

// 分支限界法求解旅行售货员问题
int bfs(const vector<vector<int>>& adj, int n, vector<int>& bestPath) {
    // 计算每个顶点的最小出边费用
    vector<int> minOutOfNode = computeMinOut(adj, n);

    // 计算所有顶点的最小出边费用之和（初始 rcost）
    int MinOutSum = 0;
    for (int val : minOutOfNode) {
        MinOutSum += val;
        cout << val << ' ';
    }
    cout << '\n';

    // 初始化优先队列
    priority_queue<MinHeapNode> pq;

    // 初始节点：从第 0 个城市出发，路径为 [0]，s=0，cc=0，rcost=totalMinOut
    MinHeapNode start;
    start.now = 0;
    start.nowCost = 0;
    start.otherCost = MinOutSum;
    start.minCost = MinOutSum;
    start.nowPath.push_back(0);
    pq.push(start);

    // 最优费用，初始为无穷大
    int bestCost = INT_MAX;

    while (!pq.empty()) {
        // 取出当前费用下界最小的节点
        MinHeapNode now = pq.top();
        pq.pop();

        // 如果当前费用下界 >= 最优费用，剪枝
        if (now.minCost >= bestCost) {
            continue;
        }

        // 如果已经遍历完所有城市（s == n-1）
        if (now.now == n - 1) {
            cout << now.now << ' ' << n - 1 << '\n';
            // 回到起点城市
            int lastToStart = adj[now.nowPath.back()][0];
            if (lastToStart != INT_MAX) {
                // 总费用 = 当前费用 + 回到起点的费用
                int totalCost = now.nowCost + lastToStart;
                if (totalCost < bestCost) {
                    bestCost = totalCost;
                    // 复制当前路径并回到起点
                    bestPath = now.nowPath;
                    bestPath.push_back(0);
                }
            }
            continue;
        }

        // 扩展子节点：遍历所有未访问的城市
        for (int i = 0; i < n; ++i) {
            // 检查城市 i 是否已经在当前路径中
            if (find(now.nowPath.begin(), now.nowPath.end(), i) != now.nowPath.end()) {
                continue;
            }

            // 检查当前城市到城市 i 的路径是否存在（费用不是 INT_MAX）
            if (adj[now.nowPath.back()][i] == INT_MAX) {
                continue;
            }

            // 生成子节点
            MinHeapNode child;
            child.now = now.now + 1;
            // 子节点的实际费用 = 当前费用 + 当前城市到城市 i 的费用
            child.nowCost = now.nowCost + adj[now.nowPath.back()][i];
            // 子节点的剩余费用 = 当前剩余费用 - 当前城市的最小出边费用
            child.otherCost = now.otherCost - minOutOfNode[now.nowPath.back()];
            // 子节点的费用下界 = 实际费用 + 剩余费用
            child.minCost = child.nowCost + child.otherCost;
            // 复制当前路径并添加新城市
            child.nowPath = now.nowPath;
            child.nowPath.push_back(i);

            // 如果子节点的费用下界 < 最优费用，则加入优先队列
            if (child.minCost < bestCost) {
                pq.push(child);
            }
        }
    }

    return bestCost;
}

int main() {
    // 城市数量
    int n = 4;
    // 费用矩阵，使用 INT_MAX 表示无穷大
    vector<vector<int>> adj = {
        {INT_MAX, 30, 6, 4},
        {30, INT_MAX, 5, 10},
        {6, 5, INT_MAX, 20},
        {4, 10, 20, INT_MAX}
    };

    // 存储最优路径
    vector<int> bestPath;

    // 求解 TSP
    int resCost = bfs(adj, n, bestPath);

    // 输出结果
    if (resCost != INT_MAX) {
        cout << "最小费用: " << resCost << endl;
        cout << "最优路径: ";
        for (size_t i = 0; i < bestPath.size(); ++i) {
            // 城市编号 +1，让输出从 1 开始
            cout << bestPath[i] + 1;
            if (i != bestPath.size() - 1) {
                cout << " -> ";
            }
        }
        cout << endl;
    }
    else {
        cout << "没有可行路径" << endl;
    }

    return 0;
}