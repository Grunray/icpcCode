/*
    //算法分类: 动态规划
    //原理: 对于每个顶点对 (u, v)，计算从 u 到 v 的最短路径，并记录路径上经过的顶点数。
    //复杂度: O(n^3)，n 为顶点数。
    //优点: 可以找到所有顶点对之间的最小环。
    //缺点: 效率较低，空间复杂度较高。
*/

#include<bits/stdc++.h>

using namespace std;

const int INF = numeric_limits<int>::max();

// 图的邻接矩阵表示
vector<vector<int>> graph;

// Floyd-Warshall 算法求解所有节点之间的最短路径
void floyd_warshall() {
  int n = graph.size();

  // 初始化距离矩阵
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (i == j) {
        graph[i][j] = 0;
      }
    }
  }

  // 动态规划，枚举中间节点 k
  for (int k = 0; k < n; k++) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (graph[i][k] != INF && graph[k][j] != INF && graph[i][k] + graph[k][j] < graph[i][j]) {
          graph[i][j] = graph[i][k] + graph[k][j];
        }
      }
    }
  }
}

// 求解图中最小环
int find_min_cycle() {
  floyd_warshall();
  int n = graph.size();
  int min_cycle = INF;

  // 遍历所有节点对
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < i; j++) {
      if (graph[i][j] != INF && graph[i][j] + graph[j][i] < min_cycle) {
        min_cycle = graph[i][j] + graph[j][i];
      }
    }
  }

  // 如果没有找到环，返回 -1
  return min_cycle == INF ? -1 : min_cycle;
}

int main() {
  int n, m;
  cin >> n >> m; // n: 节点个数，m: 边个数

  // 初始化图
  graph.assign(n, vector<int>(n, INF));

  // 输入边信息
  for (int i = 0; i < m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    graph[u][v] = w;
  }

  int min_cycle = find_min_cycle();
  cout << "最小环长度: " << min_cycle << endl;

  return 0;
}