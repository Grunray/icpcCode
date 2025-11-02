
/*
    先来看全源最短路的几个基本想法：
    1.Floyd : o(n^3)慢
    2.dijkstra : o(nmlogn) 无法处理负权
    3.BellmanFord：o(mn^2)，以每个点为源点做一次 BellmanFord


*/


#define _CRT_SECURE_NO_WARNINGS
#define itn int
#define PII pair<int, int>
#define PLI pair<long long, int>
#define frr for(int i = 0; i < n; i++)
#define frg for(register int i = 0; i < n; i++)
#define frp for(int i = 1; i <= n; i++)
#define fgp for(int i = 0; i <= n; i++)
#include<bits/stdc++.h>
using ll = long long;
using ldou = long double;
using unll = unsigned long long;
using namespace std;

const int N = 1e5 + 10;
const int INF = 1e9;
unll n, m, k;

struct edge {
	int v, w, next;
} e[N];
struct node {
	int dis, id;
	bool operator<(const node& a) const { return dis > a.dis; }
	node(int d, int x) { dis = d, id = x; }
};
int head[N], vis[N], t[N];
int cnt;
ll h[N], dis[N];
void addedge(int u, int v, int w) {
	e[++cnt].v = v;
	e[cnt].w = w;
	e[cnt].next = head[u];
	head[u] = cnt;
}
bool spfa(int s) {
	queue<int> q;
	memset(h, 63, sizeof(h));
	h[s] = 0, vis[s] = 1;
	q.push(s);
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		vis[u] = 0;
		for (int i = head[u]; i; i = e[i].next) {
			int v = e[i].v;
			if (h[v] > h[u] + e[i].w) {
				h[v] = h[u] + e[i].w;
				if (!vis[v]) {
					vis[v] = 1;
					q.push(v);
					t[v]++;
					if (t[v] == n + 1) return false;
				}
			}
		}
	}
	return true;
}
void dijkstra(int s) {
	priority_queue<node> q;
	for (int i = 1; i <= n; i++) dis[i] = INF;
	memset(vis, 0, sizeof(vis));
	dis[s] = 0;
	q.push(node(0, s));
	while (!q.empty()) {
		int u = q.top().id;
		q.pop();
		if (vis[u]) continue;
		vis[u] = 1;
		for (int i = head[u]; i; i = e[i].next) {
			int v = e[i].v;
			if (dis[v] > dis[u] + e[i].w) {
				dis[v] = dis[u] + e[i].w;
				if (!vis[v]) q.push(node(dis[v], v));
			}
		}
	}
	return;
}

void solve() {

	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		addedge(u, v, w);
	}
	for (int i = 1; i <= n; i++) addedge(0, i, 0);
	if (!spfa(0)) {
		cout << -1 << endl;
		return;
	}
	for (int u = 1; u <= n; u++)
		for (int i = head[u]; i; i = e[i].next) e[i].w += h[u] - h[e[i].v];
	for (int i = 1; i <= n; i++) {
		dijkstra(i);
		long long ans = 0;
		for (int j = 1; j <= n; j++) {
			if (dis[j] == INF)
				ans += 1ll * j * INF;
			else
				ans += 1ll * j * (dis[j] + h[j] - h[i]);
		}
		cout << ans << endl;
	}

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
