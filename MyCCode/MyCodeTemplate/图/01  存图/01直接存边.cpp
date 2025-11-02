#include <bits/stdc++.h>
using namespace std;

class t01
{
	// 01直接存边
		/*方法
		使用一个数组来存边，数组中的每个元素都包含一条边的起点与终点（带边权的图还包含边权）。
		（或者使用多个数组分别存起点，终点和边权。）*/

		/*复杂度
			01查询是否存在某条边：O(m)。
			02遍历一个点的所有出边：O(m)。
			03遍历整张图：O(nm)。
			04空间复杂度：O(m)。

			应用
			由于直接存边的遍历效率低下，一般不用于遍历图。
			在 Kruskal 算法 中，由于需要将边按边权排序，需要直接存边。
			在有的题目中，需要多次建图（如建一遍原图，建一遍反图），
				此时既可以使用多个其它数据结构来同时存储多张图，
				也可以将边直接存下来，需要重新建图时利用直接存下的边来建图。*/

	struct Edge {
		int u, v, w; // 起点，终点，权值
	};

	int n, m;
	vector<Edge> e;
	vector<bool> vis;

	bool find_edge(int u, int v) {
		for (int i = 1; i <= m; ++i) {
			if (e[i].u == u && e[i].v == v /*|| e[i].v == u && e[i].u == v*/) {
				return true;
			}
		}
		return false;
	}

	void dfs(int u) {
		if (vis[u]) return;
		vis[u] = true;
		for (int i = 1; i <= m; ++i) {
			if (e[i].u == u) {
				dfs(e[i].v);
				cout << "  u  " << u << '\n';
				cout << "  i  " << i << ' ';
				cout << e[i].u << ' ' << e[i].v << '\n';
			}
		}
		cout << '\n';
	}

	int main() {
		cin >> n >> m;

		vis.resize(n + 1, false);
		e.resize(m + 1);

		for (int i = 1; i <= m; ++i) cin >> e[i].u >> e[i].v;

		if (find_edge(1, 2)) cout << " 1 - 2  右边\n";
		if (find_edge(1, 3)) cout << " 1 - 3  右边\n";
		if (find_edge(1, 5)) cout << " 1 - 5  右边\n";
		cout << "****************\n";
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





