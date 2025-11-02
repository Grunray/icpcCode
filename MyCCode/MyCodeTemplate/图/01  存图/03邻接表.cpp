#include <bits/stdc++.h>
using namespace std;

class t03
{
	/*邻接表
	方法
		使用一个支持动态增加元素的数据结构构成的数组，
			如 vector<int> adj[n + 1] 来存边，
			其中 adj[u] 存储的是点 u 的所有出边的相关信息（终点、边权等）。*/
	/*复杂度
		01查询是否存在 u 到 v 的边：O(d ^ +(u))（如果事先进行了排序就可以使用 二分查找 做到 O(\log(d ^ +(u)))）。
		02遍历点 u 的所有出边：O(d ^ +(u))。
		03遍历整张图：O(n + m)。
		04空间复杂度：O(m)。
	应用
		存各种图都很适合，除非有特殊需求（如需要快速查询一条边是否存在，且点数较少，可以使用邻接矩阵）。
		尤其适用于需要对一个点的所有出边进行排序的场合。*/

	int n, m;
	vector<bool> vis;
	vector<vector<int> > adj; // 二维存的是 一维的点 的所有的出边

	bool find_edge(int u, int v) {
		for (int i = 0; i < adj[u].size(); ++i) {
			if (adj[u][i] == v /*|| adj[v][i] == u*/) { // 无向则加判断条件
				return true;
			}
		}
		return false;
	}

	void dfs(int u) {
		if (vis[u]) return;
		vis[u] = true;
		for (int i = 0; i < adj[u].size(); ++i) {
			dfs(adj[u][i]);
			cout << " u - i " << u << '-'  << adj[u][i] << '\n'; // u的 所有出边// u-?有哪些边
		}
			
	}

	int main() {
		cin >> n >> m;

		vis.resize(n + 1, false);
		adj.resize(n + 1);

		for (int i = 1; i <= m; ++i) {
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
		}

		if (find_edge(1, 2))cout << " 1-2  youbian\n";
		if (find_edge(1, 3))cout << " 1-3  youbian\n";
		if (find_edge(1, 5))cout << " 1-5  youbian\n";
		cout << "*******\n";
		dfs(1);

		return 0;
	}

	/*
	5 6
	1 2
	2 3
	3 4
	4 5
	5 1
	2 4
	*/
};