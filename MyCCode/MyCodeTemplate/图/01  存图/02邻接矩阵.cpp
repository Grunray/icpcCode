#include <bits/stdc++.h>
using namespace std;

class t02
{
	/*邻接矩阵
	方法
		使用一个二维数组 adj 来存边，
			其中 adj[u][v] 为 1 表示存在 u 到 v 的边，为 0 表示不存在。
			如果是带边权的图，可以在 adj[u][v] 中存储 u 到 v 的边的边权。*/
	/*复杂度
		01查询是否存在某条边：O(1)。
		02遍历一个点的所有出边：O(n)。
		03遍历整张图：O(n ^ 2)。
		04空间复杂度：O(n ^ 2)。

	应用
		邻接矩阵只适用于没有重边（或重边可以忽略）的情况。
		其最显著的优点是可以 O(1) 查询一条边是否存在。
		由于邻接矩阵在稀疏图上效率很低（尤其是在点数较多的图上，空间无法承受），
		所以一般只会在稠密图上使用邻接矩阵。*/
	int n, m;
	vector<bool> vis;
	vector<vector<bool> > adj;

	bool find_edge(int u, int v) { return adj[u][v]; }

	void dfs(int u) {
		if (vis[u]) return;
		vis[u] = true;
		for (int v = 1; v <= n; ++v) {
			if (adj[u][v]) {
				dfs(v);
			}
		}
	}

	int main02() {
		cin >> n >> m;

		vis.resize(n + 1, false);
		adj.resize(n + 1, vector<bool>(n + 1, false));

		for (int i = 1; i <= m; ++i) {
			int u, v;
			cin >> u >> v;
			adj[u][v] = true;
		}

		return 0;
	}
};