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

const int N = 2e6 + 50;
const int M = 2e5 + 50;
const ll INF = 0x3f3f3f3f;
const ll MODE = ll(998244353);
const double Pi = 3.1415926;
const double eps = 1e-8;
const int dx[4] = { 1,-1, 0, 0 };
const int dy[4] = { 0, 0, 1,-1 };
//priority_queue<int> p;//这是一个大根堆q
//priority_queue<int, vector<int>, greater<int> >q;//这是一个小根堆q
//priority_queue<ll, vector<ll>, greater<ll> >pq; // 小根
ll n, m, k;

int c, dis[N];
vector<int> adj[N];

void dfs(int u, int fa) {
	for (int v : adj[u]) {
		if (v == fa) continue;

		dis[v] = dis[u] + 1;

		if (dis[v] > dis[c]) c = v;

		dfs(v, u);
	}
}
void dfs_solve() {
	cin >> n;

	for (int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v), adj[v].push_back(u);
	}

	dfs(1, 0);

	/*rep(i, 1, n) {
		cout << d[i] << ' ';
	}cout << '\n';*/

	// 不用给记录距离的数组d重置大小的原因 ： dfs中是直接 = ，不是++
	dis[c] = 0; dfs(c, 0);

	/*rep(i, 1, n) {
		cout << d[i] << ' ';
	}cout << '\n';*/

	cout << dis[c] << '\n';
}

/*
	如果需要求出一条直径上所有的节点，则可以在 DP 的过程中，
	记录下每个节点能向下延伸的最长路径与次长路径（定义同上）所对应的子节点，
	在求 d 的同时记下对应的节点 u，使得 d = d_1[u] + d_2[u]，
	即可分别沿着从 u 开始的最长路径的次长路径对应的子节点一路向某个方向
	（对于无根树，虽然这里指定了 1 为树的根，
	但仍需记录每点跳转的方向；对于有根树，一路向上跳即可），遍历直径上所有的节点。
*/
int d1[N], d2[N];
int d;
void dp(int u, int fa) {
	d1[u] = d2[u] = 0;
	for (int v : adj[u]) {
		if (v == fa) continue;
		dp(v, u);
		int t = d1[v] + 1;
		if (t > d1[u])
			d2[u] = d1[u], d1[u] = t;
		else if (t > d2[u])
			d2[u] = t;
	}
	d = max(d, d1[u] + d2[u]);
}

void dp_solve() {
	cin >> n;

	for (int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v), adj[v].push_back(u);
	}

	dfs(1, 0);

	cout << d << '\n';
}


void solve() {

	
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
