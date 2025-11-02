// cnt[x]:表示x的入队次数

#define _CRT_SECURE_NO_WARNINGS
#define itn int
#define PII pair<int, int>
#define PLI pair<long long, int>
#define frr for(int i = 0; i < n; i++)
#define frg for(register int i = 0; i < n; i++)
#define frp for(int i = 1; i <= n; i++)
#define fgp for(int i = 0; i <= n; i++)
#define fep(i,a,b) for(int i = (a); i >= (b); --i)
#define rep(i,a,b) for(int i = (a); i <= (b); ++i)
#include<bits/stdc++.h>
using ll = long long;
using ldou = long double;
using unll = unsigned long long;
using namespace std;

const int N = 1e5 + 10;
const int INF = 0x3f3f3f3f * 1ll;
unll n, m, k;

void solve() {

	cin >> n >> m;
	vector<vector<PII> >g(n + 1);

	int u, v, w, tm = m;
	while (tm--) {
		cin >> u >> v >> w;
		g[u].push_back({ v,w });
		if (w >= 0) g[v].push_back({ u,w });
	}
	
	vector<int>inq(n + 1, 0);
	vector<int>cnt(n + 1, 0);
	vector<int>d(n + 1, INF);
	queue<int>q;

	q.push(1);
	inq[1] = 1;
	d[1] = 0;

	/*rep(i, 1, n) {
		q.push(i);
		inq[i] = 1;
	}*/

	while (q.size()) {
		auto t = q.front(); q.pop();
		int u = t;
		inq[u] = 0;
		for (auto it : g[u]) {
			int v = it.first, w = it.second;
			if (d[v] > d[u] + w) {
				d[v] = d[u] + w;
				if (!inq[v]) {
					q.push(v);
					inq[v] = 1;
					if (++cnt[v] >= n) {
						cout << "YES\n";
						return;
					}
				}
			}
		}
	}
	cout << "NO\n";
}

signed main() {
	std::ios::sync_with_stdio(false), std::cin.tie(0), std::cout.tie(0);
	//freopen("wrt.txt", "r", stdin); //freopen("out.txt", "w", stdout);
	int TTT = 1; cin >> TTT;
	while (TTT--) {
		solve();
	}

	return 0;
}