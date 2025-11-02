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
const int M = 3e7 + 50;
const ll INF = 0x3f3f3f3f;
const ll MODE = ll(100003);
const double Pi = acos(-1);
const double eps = 1e-7;
const int dx[4] = { 1,-1, 0, 0 };
const int dy[4] = { 0, 0, 1,-1 };
int months[15] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
//priority_queue<ll> pq;//这是一个大根堆q
//priority_queue<int, vector<int>, greater<int> >q;//这是一个小根堆q
//priority_queue<ll, vector<ll>, greater<ll> >pq; // 小根
ll n, m, k;


vector<vector<int> >adj;
queue<ll>q;

void dfs(int u) {

	/*for (auto v : adj[u]) {
		if (v) {
			v = 0;
			dfs(v);
		}
	}*/

	for (int i = 0; i < adj[u].size(); i++) {
		int v = adj[u][i];
		if (v) {
			adj[u][i] = 0;
			dfs(v);
		}
	}

	q.push(u);
}

void solve() {

	cin >> n >> m;

	adj.resize(n + 5);

	ll u, v;
	rep(i, 1, m) {
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	dfs(1);

	while (!q.empty()) {
		cout << q.front() << '\n';
		q.pop();
	}


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