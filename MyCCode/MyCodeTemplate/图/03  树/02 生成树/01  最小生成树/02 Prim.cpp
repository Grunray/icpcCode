#define _CRT_SECURE_NO_WARNINGS
#define itn int
#define PII pair<int, int>
#define PLI pair<long long, int>
#define fep(i, a, b) for(int i = (a); i >= (b); --i)
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
#include<bits/stdc++.h>
#include<unordered_map>
using ll = long long;
using ldou = long double;
using unll = unsigned long long;
using namespace std;

inline int read() {
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch>'9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - 48; ch = getchar(); }
	return x * f;
}

ll gcd(ll a, ll b) { // 最大公约数
	while (b ^= a ^= b ^= a %= b)
		;
	return a;
}
ll lcm(ll a, ll b) { // 最小公倍数
	return a / gcd(a, b) * b;
}
ll qmi(ll m, ll k, ll p) { // 快速幂
	//求 m^k mod p，时间复杂度 O(logk)。
	//m为底数，k为幂
	ll res = 1 % p, t = m;
	while (k) {
		if (k & 1) res = res * t % p;
		t = t * t % p;
		k >>= 1;
	}
	return res;
}
unll qmi(unll m, unll k, unll p) { //龟速乘
	ll res = 0, t = m;
	while (k) {
		if (k & 1) res = (res + t) % p;
		k >>= 1;
		t = (t << 1) % p;
	}
	return res;
}

////////////////////////////////////////////////////////////////////////////////

ll n, m, k;
const int N = 2e5 + 50;
const ll INF = 1e9;
const ll MODE = ll(998244353);
const int dx[4] = { 1,-1, 0, 0 };
const int dy[4] = { 0, 0, 1,-1 };
//priority_queue<int> p;//这是一个大根堆q
//priority_queue<int, vector<int>, greater<int> >q;//这是一个小根堆q
//priority_queue<ll, vector<ll>, greater<ll> >pq; // 小根

struct Edge
{
	ll v, w, x;
}e[N * 2]; // 边的两倍

int cnt_e;
ll h[N];
void adde(int u, int v, int w) {
	e[++cnt_e] = Edge{ v,w,h[u] };
	h[u] = cnt_e;
}

struct S
{
	int u, d;
};
bool operator < (const S& x, const S& y) { return x.d > y.d; }

priority_queue<S>q;
ll dis[N];
bool vis[N];
ll res, cnt;

void Prim() {
	memset(dis, 0x3f, sizeof dis);
	dis[1] = 0;
	q.push({ 1,0 });

	while (!q.empty()) {
		if (cnt >= n) break;
		int u = q.top().u;
		int d = q.top().d;
		q.pop();

		if (vis[u]) continue;
		vis[u] = true;

		++cnt;
		res += d;

		for (int i = h[u]; i; i = e[i].x) {
			int v = e[i].v;
			int w = e[i].w;

			if (w < dis[v]) {
				dis[v] = w;
				q.push({ v, w });
			}
		}

	}
}

void solve() {

	cin >> n >> m;

	int u, v, w;
	rep(i, 1, m) {
		cin >> u >> v >> w;
		adde(u, v, w);
		adde(v, u, w);
	}

	Prim();

	if (cnt == n)
		cout << res << '\n';
	else
		cout << "orz\n";


}

signed main() {
	std::ios::sync_with_stdio(false); std::cin.tie(0), std::cout.tie(0);
	/*freopen("out.txt", "r", stdin);
	freopen("wrt.txt", "w", stdout);*/
	int TTT = 1; //cin >> TTT;
	while (TTT--) {
		solve();
	}
	/*while (cin >> n >> m) {
		solve();
	}*/

	return 0;
}