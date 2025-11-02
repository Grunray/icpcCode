#define _CRT_SECURE_NO_WARNINGS
#define IOS std::ios::sync_with_stdio(false), std::cin.tie(0), std::cout.tie(0);
#define inout freopen("wrt.txt", "r", stdin); freopen("out.txt", "w", stdout);
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

const int N = 2e5 + 5;
const ll INF = 3e16;
const int MODE = 998244353;
unll n, m, k;

void solve() {

	cin >> n >> m;

	vector<vector<pair<int, ll> > > adj(n);
	vector<ll>dis(n, 1e18), wei(n);
	priority_queue<pair<ll, int> >pq;

	for (int i = 0; i < n; i++)
		cin >> wei[i];
	
	int u, v, w;
	for (int i = 0; i < m; i++) {
		cin >> u >> v >> w;
		u--; v--;
		adj[u].push_back({ v,w });
		adj[v].push_back({ u,w });
	}

	dis[0] = wei[0];

	pq.push({ -1 * wei[0], 0 });

	while (!pq.empty()) {
		auto top = pq.top(); pq.pop();
		ll u = top.second;
		ll d = -top.first;

		if (d > dis[u])continue;

		for (auto& e : adj[u]) {
			int v = e.first, w = e.second;
			if (dis[v] > d + w + wei[v]) {
				dis[v] = d + w + wei[v];
				pq.push({ -dis[v], v });
			}
		}
	}

	for (int i = 1; i < n; i++)
		cout << dis[i] << ' ';


}

signed main() {
	//IOS;
	//inout;
	int TTT = 1; //cin >> TTT;
	while (TTT--)
		solve();
	return 0;
}