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

unll n, m, k;

const int N = 2e5 + 5;
const ll INF = 0x3f3f3f3f;

int vis[N], dfn[N], low[N], id;
int ans;
int s[N], tp, cnt, h[N];

struct edge {
	int to, nt;
}e[N << 1];



void add(int u, int v) {
	e[++cnt] = { v,h[u] }, h[u] = cnt;
}

void dfs(int u, int fa) {
	dfn[u] = low[u] = ++id; vis[u] = 1; s[++tp] = u;
	for (int i = h[u]; i; i = e[i].nt) {
		int v = e[i].to;
		if (!dfn[v]) {
			dfs(v, u);
			low[u] = min(low[u], low[v]);
		}
		else if (v != fa) {
			low[u] = min(low[u], dfn[v]);
		}
	}
	if (dfn[u] == low[u]) {
		int sum = 1;
		while (s[tp] != u) {
			vis[s[tp--]] = 0, sum++;
		}
		tp--;
		if (sum == 2) {
			puts("2"); exit(0);
		}
		if (sum > 1) ans = min(ans, sum);
	}
}

void solve() {

	cin >> n;
	frp{
		int x; cin >> x;
		add(i, x);
	}
	ans = INF;
	frp if (!dfn[i]) dfs(i, 0);
	if (ans == INF)
		cout << "No\n";
	else
		cout << "Yes\n";
	cout << ans << '\n';
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
