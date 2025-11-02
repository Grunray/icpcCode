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
	int x = 0, f = 1;
	char ch = getchar();
	while (!isdigit(ch)) { f = ch != '-'; ch = getchar(); }
	while (isdigit(ch)) { x = (x << 1) + (x << 3) + (ch ^ 48); ch = getchar(); }
	return f ? x : -x;
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
unll gml(unll m, unll k, unll p) { //龟速乘
	ll res = 0, t = m;
	while (k) {
		if (k & 1) res = (res + t) % p;
		k >>= 1;
		t = (t << 1) % p;
	}
	return res;
}

////////////////////////////////////////////////////////////////////////////////

const int N = 2e5 + 50;
const int M = 2e5 + 50;
const ll INF = 0x3f3f3f3f;
const ll MODE = ll(998244353);
const double Pi = 3.1415926;
const double eps = 1e-8;
const int dx[4] = { 1,-1, 0, 0 };
const int dy[4] = { 0, 0, 1,-1 };
//priority_queue<ll> pq;//这是一个大根堆q
//priority_queue<int, vector<int>, greater<int> >q;//这是一个小根堆q
priority_queue<ll, vector<ll>, greater<ll> >pq; // 小根
ll n, m, k;

ll d, p, c, f, s;

ll dis[N], vis[N], head[N];
//记录到 i 城市 cnt[i] 次
ll cnt[N];

struct Edge
{
	ll next, to, dis;
}edge[N];

void addedge(ll u, ll v, ll w) {
	edge[++m].next = head[u];
	edge[m].to = v;
	edge[m].dis = w;
	//dis[m] = w;
	head[u] = m;
}

void spfa(ll st) {

	//queue<ll> q;
	pq.push(st);

	/*for (int i = 1; i <= n; i++) {
		dis[i] = INF;
		vis[i] = 0;
	}*/
	
	dis[st] = d;
	vis[st] = 1;
	cnt[st]++;

	while (!pq.empty()) {
		ll u = pq.top(); pq.pop();
		vis[u] = 0;

		if (++cnt[u] > c) {
			cout << -1;
			exit(0);
		}

		for (int i = head[u]; i; i = edge[i].next) {
			ll v = edge[i].to;
			if (dis[v] < dis[u] + edge[i].dis/*dis[i]*/) {
				dis[v] = dis[u] + edge[i].dis/*dis[i]*/;
				if (!vis[v]) {
					vis[v] = 1;
					pq.push(v);
				}
			}
		}
	}
}

void solve() {

	cin >> d >> p >> c >> f >> s;

	ll u, v, w;
	w = d;
	
	// 点权转化为边权
	rep(i, 1, p) {
		cin >> u >> v;
		addedge(u, v, w);
	}
	// 特殊处理点权->边权
    // 可能会有负边 所以用SPFA
	rep(i, 1, f) {
		cin >> u >> v >> w;
		addedge(u, v, d - w);
	}

	spfa(s);

	ll res = 0;
	rep(i, 1, c) {
		res = max(res, dis[i]);
		//cout << dis[i] << ' ';
	}
	//cout << '\n';
	cout << res << '\n';
	//cout << dis[c];
	
}

signed main() {
	std::ios::sync_with_stdio(false); std::cin.tie(0), std::cout.tie(0);
	//freopen("wrt.txt", "r", stdin);
	//freopen("wrt.txt", "w", stdout);
	int TTT = 1; //cin >> TTT;
	while (TTT--) {
		solve();
	}
	/*while (cin >> n >> m) {
		solve();
	}*/

	return 0;
}
