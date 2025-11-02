//按题目来每次考虑每个点可以到达点编号最大的点，不如考虑较大的点可以反向到达哪些点

#define _CRT_SECURE_NO_WARNINGS
#define itn int
#define PII pair<int, int>
#define PLI pair<long long, int>
#define fep(i,a,b) for(int i = (a); i >= (b); --i)
#define rep(i,a,b) for(int i = (a); i <= (b); ++i)
#include<bits/stdc++.h>
using ll = long long;
using ldou = long double;
using unll = unsigned long long;
using namespace std;
//////////////////////////////////////////////////////////////////////////////////

unll n, m, k;
string str;
const int N = 1e5 + 5;
const ll INF = 0x3f3f3f3f;
const ll MODE = ll(1e6 + 7);

vector<bool> vis;
vector<vector<int> > adj;
queue<int>q;

//int maxn;
//void findmx(int u, int pos) {
//
//	vis[u] = true;
//	//cout << u << ' ';
//	if (pos == n)return;
//	for (int i = 0; i < adj[u].size(); i++)
//		if (!vis[adj[u][i]]) {
//			maxn = max(maxn, adj[u][i]);
//			findmx(adj[u][i], pos + 1);
//		}
//}

int maxn[N]; //int ans = 0;
void dfs(int u, int val) {
	if (maxn[u]) return;
	maxn[u] = val;
	/*cout << "   " << ++ans << '\n';
	cout << "  maxn[u] = " << u << ' ' << maxn[u] << '\n';*/
	for (int i = 0; i < adj[u].size(); i++)
		dfs(adj[u][i], val);
}

void solve() {

	cin >> n >> m;

	vis.resize(n + 1, false);
	adj.resize(n + 1);

	/*//暴了！
	int u, v;
	rep(i, 1, m) {
		cin >> u >> v;
		adj[u].push_back(v);
	}
	for (int i = 1; i <= n; i++) {
		maxn = i;
		fill(vis.begin(), vis.end(), false);
		findmx(i, 0);
		cout << maxn << ' ';
	}//喜提TLE--yiwu
	*/

	int u, v;
	rep(i, 1, m) {
		cin >> u >> v;
		adj[v].push_back(u); //****** 建反图
	}

	//循环从N到1，则每个点i能访问到的结点的A值都是i
	//每个点访问一次，这个A值就是最优的，因为之后如果再访问到这个结点那么答案肯定没当前大了
	fep(i, n, 1) dfs(i, i);
	
	
	rep(i, 1, n) cout << maxn[i] << ' ';

}

signed main() {
	std::ios::sync_with_stdio(false), std::cin.tie(0), std::cout.tie(0);
	//freopen("wrt.txt", "r", stdin); //freopen("out.txt", "w", stdout);
	int TTT = 1; //cin >> TTT;
	while (TTT--) {
		solve();
	}

	return 0;
}