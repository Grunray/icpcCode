
// o(n^3)
// 可以查找最小环路径节点 与 长度

#define _CRT_SECURE_NO_WARNINGS
#define itn int
#define PII pair<int, int>
#define frr for(int i = 0; i < n; i++)
#define frg for(register int i = 0; i < n; i++)
#define frp for(int i = 1; i <= n; i++)
#define fgp for(int i = 0; i <= n; i++)
#include<bits/stdc++.h>
using ll = long long;
using ldou = long double;
using unll = unsigned long long;
using namespace std;

unll n, m, k;

const int N = 105;
const ll INF = 0x3f3f3f3f;

int g[N][N], d[N][N];
int pos[N][N];//pos[i][j]表示i和j最短路经过k点中转
vector<int> path; //保存最小环路径

void get_path(int i, int j)
{
	if (pos[i][j] == 0) return; //i和j之间不存在中转点
	int k = pos[i][j]; //k是i和j最最短路的中转点
	get_path(i, k); //递归后取i-k最短路上的节点
	path.push_back(k);
	get_path(k, j); //递归后取k-j最短路上的节点
}

void solve() {

	cin >> n >> m;
	memset(g, 0x3f, sizeof g); //初始化邻接矩阵
	for (int i = 1; i <= n; i++) g[i][i] = 0;
	while (m--)
	{
		int a, b, c;
		cin >> a >> b >> c;
		g[a][b] = g[b][a] = min(g[a][b], c); //无向图，可能存在重边
	}
	int ans = INF;
	memcpy(d, g, sizeof d); //初始化最短路
	for (int k = 1; k <= n; k++)
	{
		//计算由编号不超过k的节点构成的最小环
		for (int i = 1; i < k; i++) //枚举环中的点
			for (int j = i + 1; j < k; j++)
			{
				if ((long long)d[i][j] + g[j][k] + g[k][i] < ans) //出现更小的环
				{
					ans = d[i][j] + g[j][k] + g[k][i];
					path.clear(); //清除之前的最小环路径
					path.push_back(k); //k-i-最短路路径-j
					path.push_back(i);
					get_path(i, j);//获取i-j最短路径上的节点
					path.push_back(j);
				}
			}
		//计算最短路
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				if (d[i][j] > d[i][k] + d[k][j])
				{
					d[i][j] = d[i][k] + d[k][j];
					pos[i][j] = k; //记录最短路中转点
				}
	}
	if (ans == INF)cout << "No solution.\n";
	else //存在最小环
	{
        //////////////////  路径
		for (int i : path) cout << i << " ";
		cout << '\n';
		
        //////////////////  长度
		ll res = 0;
		for (int i = 1; i < path.size(); i++)
			res += g[path[i]][path[i - 1]];
		res += g[path[0]][path[path.size() - 1]];
		cout << res;

	}
}

signed main() {
	//std::ios::sync_with_stdio(false), std::cin.tie(0), std::cout.tie(0);
	//freopen("wrt.txt", "r", stdin); //freopen("out.txt", "w", stdout);
	int TTT = 1; //cin >> TTT;
	while (TTT--) {
		solve();
	}
		
	return 0;
}
