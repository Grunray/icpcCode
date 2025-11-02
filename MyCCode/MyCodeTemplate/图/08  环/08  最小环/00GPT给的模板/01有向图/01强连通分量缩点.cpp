/*
    算法分类: 图搜索
    原理: 首先求出图的所有强连通分量，并将其缩点为一个节点。然后在缩点后的图中使用 DFS 寻找最小环。
    复杂度: O(n+m)，n 为顶点数，m 为边数。
    优点: 效率高，可以找到图中所有最小环。
    缺点: 算法较为复杂。
*/

#include<bits/stdc++.h>

using namespace std;

const int INF = numeric_limits<int>::max();

// 图的邻接矩阵表示
vector<vector<int>> graph;

// 深度优先搜索
void dfs(int u, vector<bool>& visited, stack<int>& st) {
  visited[u] = true;
  for (int v = 0; v < graph.size(); v++) {
    if (graph[u][v] != INF && !visited[v]) {
      dfs(v, visited, st);
    }
  }
  st.push(u);
}

// 逆向图的深度优先搜索
void dfs_reverse(int u, vector<bool>& visited) {
  visited[u] = true;
  for (int v = 0; v < graph.size(); v++) {
    if (graph[v][u] != INF && !visited[v]) {
      dfs_reverse(v, visited);
    }
  }
}

// 寻找强连通分量
vector<vector<int>> find_scc() {
  int n = graph.size();
  vector<bool> visited(n, false);
  stack<int> st;

  // 对每个未访问的节点进行 DFS
  for (int i = 0; i < n; i++) {
    if (!visited[i]) {
      dfs(i, visited, st);
    }
  }

  // 创建逆向图
  vector<vector<int>> graph_reverse(n, vector<int>(n, INF));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (graph[i][j] != INF) {
        graph_reverse[j][i] = graph[i][j];
      }
    }
  }

  // 在逆向图上进行 DFS，寻找强连通分量
  visited.assign(n, false);
  vector<vector<int>> scc;
  while (!st.empty()) {
    int u = st.top();
    st.pop();
    if (!visited[u]) {
      vector<int> component;
      dfs_reverse(u, visited);
      for (int i = 0; i < n; i++) {
        if (visited[i]) {
          component.push_back(i);
        }
      }
      scc.push_back(component);
    }
  }
  return scc;
}

// 在强连通分量图中寻找最小环
int find_min_cycle_scc() {
  vector<vector<int>> scc = find_scc();
  int n_scc = scc.size();

  // 创建强连通分量图
  vector<vector<int>> graph_scc(n_scc, vector<int>(n_scc, INF));
  for (int i = 0; i < n_scc; i++) {
    for (int u : scc[i]) {
      for (int j = 0; j < n_scc; j++) {
        for (int v : scc[j]) {
          if (graph[u][v] != INF) {
            graph_scc[i][j] = min(graph_scc[i][j], graph[u][v]);
          }
        }
      }
    }
  }

  // 在强连通分量图中寻找最小环
  int min_cycle = INF;
  for (int i = 0; i < n_scc; i++) {
    for (int j = 0; j < i; j++) {
      if (graph_scc[i][j] != INF) {
        min_cycle = min(min_cycle, graph_scc[i][j] + 1);
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

  int min_cycle = find_min_cycle_scc();
  cout << "最小环长度: " << min_cycle << endl;

  return 0;
}