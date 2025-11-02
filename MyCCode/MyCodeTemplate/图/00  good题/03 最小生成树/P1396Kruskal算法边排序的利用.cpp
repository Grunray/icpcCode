
/*
    因为是按照边的权值排序的，所以直接输出当前边的权值，就是输出联通之后st->ed的最大权
*/

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
const int N = 2e4 + 50;
const int M = 2e4 + 50;
const ll INF = 1e9;
const ll MODE = ll(998244353);
const int dx[4] = { 1,-1, 0, 0 };
const int dy[4] = { 0, 0, 1,-1 };
//priority_queue<int> p;//这是一个大根堆q
//priority_queue<int, vector<int>, greater<int> >q;//这是一个小根堆q
//priority_queue<ll, vector<ll>, greater<ll> >pq; // 小根

struct NODE
{
	int u, v, w;
	bool vis = false;
}node[M];

bool cmp(NODE n1, NODE n2) {
	return n1.w < n2.w;
}

ll fa[N];

ll findfa(int x) {
	if (x == fa[x])
		return x;
	else
		return fa[x] = findfa(fa[x]);
}

void addfa(int x, int y) {
	x = findfa(x); y = findfa(y);

	if (x == y) return;
	fa[x] = y;
}

void solve() {

	ll st, ed;
	cin >> n >> m >> st >> ed;

	rep(i, 1, m) cin >> node[i].u >> node[i].v >> node[i].w;

	sort(node + 1, node + m + 1, cmp);

	rep(i, 1, n) fa[i] = i;

	int tm = 0; // 记录当前有多少边已经连接
	ll res = 0; // 权值
	rep(i, 1, m) {
		if (tm == n - 1) break; // 如果 当前边 = 点数 - 1，无环图变数为 n - 1
		if (findfa(node[i].u) != findfa(node[i].v)) { // 如果两点没有访问过

			addfa(node[i].u, node[i].v);

			node[i].vis = true;

			res += node[i].w;
			tm++;
		}

		// 因为是按照边的权值排序的，所以直接输出当前边的权值，就是输出联通之后st->ed的最大权
		if (findfa(st) == findfa(ed)) {
			cout << node[i].w << '\n';
			return;
		}
	}

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