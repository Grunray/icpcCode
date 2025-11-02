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

unll n, m, k;
string str;
const int N = 2e4 + 5;
const ll INF = 0x3f3f3f3f;
const ll MODE = ll(1e6 + 7);

vector<bool> vis;
vector<vector<int> > adj;
queue<int>q;
int cnt;

void init() {
	cin >> n >> m;

	vis.resize(n + 1, false);
	adj.resize(n + 1);

	int u, v;
	rep(i, 1, m) {
		cin >> u >> v;
		adj[u].push_back(v);
	}
    //题目要求先排序
	rep(i, 1, n) sort(adj[i].begin(), adj[i].end()); 
}

void dfs(int u, int x) {
	
	vis[u] = 1;
	cout << u << ' ';
	if (x == n)return;
	//rep(i, 0, (adj[u].size() - 1))
	for(int i = 0; i < adj[u].size(); i++)
		if(!vis[adj[u][i]])
			dfs(adj[u][i], x + 1);

}

void bfs(int v) {

	fill(vis.begin(), vis.end(), false);
	vis[v] = true;
	q.push(v);

	while (!q.empty()) {
		int u = q.front(); q.pop();

		cout << u << ' ';

		for(int i = 0; i < adj[u].size(); i++)
			if (!vis[adj[u][i]]) {
				vis[adj[u][i]] = true;
				q.push(adj[u][i]);
			}
	}
}

void solve() {

    init();
	dfs(1, 0);
	cout << '\n';
	bfs(1);

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
