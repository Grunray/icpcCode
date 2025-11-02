/*
    算法分类: 动态规划
    原理: 迭代更新每个顶点到源点的最短路径，并记录路径上经过的顶点数。
    复杂度: O(n*m)，n 为顶点数，m 为边数。
    优点: 相对 Floyd-Warshall 算法，效率更高。
    缺点: 只能找到源点到其他顶点的最小环。
*/
#include<bits/stdc++.h>

using namespace std;

const int INF = numeric_limits<int>::max();

// 图的邻接矩阵表示
vector<vector<int>> graph;

// Bellman-Ford 算法求解单源最短路径
bool bellman_ford(int s, vector<int>& dist) {
  dist.assign(graph.size(), INF);
  dist[s] = 0;

  // 松弛操作，最多执行 n - 1 次
  for (int i = 0; i < graph.size() - 1; i++) {
    for (int u = 0; u < graph.size(); u++) {
      for (int v = 0; v < graph.size(); v++) {
        if (graph[u][v] != INF && dist[u] != INF && dist[u] + graph[u][v] < dist[v]) {
          dist[v] = dist[u] + graph[u][v];
        }
      }
    }
  }

  // 检测是否存在负权环
  for (int u = 0; u < graph.size(); u++) {
    for (int v = 0; v < graph.size(); v++) {
      if (graph[u][v] != INF && dist[u] != INF && dist[u] + graph[u][v] < dist[v]) {
        return false; // 存在负权环
      }
    }
  }
  return true; // 不存在负权环
}

// 求解图中最小环
int find_min_cycle() {
  int n = graph.size();
  int min_cycle = INF;

  // 遍历所有节点
  for (int i = 0; i < n; i++) {
    // 计算以节点 i 为起点的单源最短路径
    vector<int> dist(n, INF);
    if (bellman_ford(i, dist)) {
      // 遍历所有节点，寻找最小环
      for (int j = 0; j < n; j++) {
        if (i != j && graph[j][i] != INF && dist[j] != INF && dist[j] + graph[j][i] < min_cycle) {
          min_cycle = dist[j] + graph[j][i];
        }
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