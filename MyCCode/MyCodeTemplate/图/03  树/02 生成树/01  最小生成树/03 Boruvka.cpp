
/*
    用于求解无向图的最小生成森林。（无向连通图就是最小生成树。）

    Borůvka 其实是一种多路增广的 prim

    Prim 算法由一个点开始，往外不断贪心地找最短边，然后不断扩大连通块，直到形成一棵树。
    而 Borůvka 算法每一次的增广，会对现在的每一个连通块都找一遍的最短边，最后每个连通块择优，将这些边全部连上。

    算法的执行流程大约是这样的：

    对于现在的每个连通块，找到从这个连通块出发，不在最小生成树中的、到达别的连通块的最短边。
    （特别注意：若权值相同，则需要再按照另一个维度严格排序，常用标号大小排序。即边权相同时，认为编号小的边短。
        这样处理是为了避免两个连通块互相连的时候出现环）
    全部找完后，将这些边加入最小生成树中。（
        可能出现两个连通块互连的情况，那么这时在第一个连通块连完这条边后，
        标记一下，说明该边已被加入最小生成树，下一次弹掉即可）
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
const int N = 5e4 + 50;
const int M = 2e5 + 50;
const ll INF = 1e9;
const ll MODE = ll(998244353);
const int dx[4] = { 1,-1, 0, 0 };
const int dy[4] = { 0, 0, 1,-1 };
//priority_queue<int> p;//这是一个大根堆q
//priority_queue<int, vector<int>, greater<int> >q;//这是一个小根堆q
//priority_queue<ll, vector<ll>, greater<ll> >pq; // 小根

int fa[N];
int best[N];
int u[M], v[M], w[M];
int vis[M];

int findfa(int x) {
	if (x == fa[x]) return x;
	else  return fa[x] = findfa(fa[x]);
}

bool Better(int x, int y) {
	if (y == 0)return true;
	if (w[x] != w[y])return w[x] < w[y];
	return x < y;
}

void solve() {

	cin >> n >> m;

	rep(i, 1, m)
		cin >> u[i] >> v[i] >> w[i];

	rep(i, 1, n) fa[i] = i;

	ll sum = 0, ans = 0;
	bool is = true;
	while (is) {
		is = false;
		memset(best, 0, sizeof best);

		rep(i, 1, m) {
			if (vis[i]) continue;

			int x = findfa(u[i]);
			int y = findfa(v[i]);

			if (x == y)continue;

			if (Better(i, best[x])) best[x] = i;
			if (Better(i, best[y])) best[y] = i;
		}

		rep(i, 1, n)
			if (best[i] && !vis[best[i]]) {
				is = true;

				sum += w[best[i]];
				ans++;

				vis[best[i]] = true;

				fa[findfa(u[best[i]])] = findfa(v[best[i]]);
			}
	}
	if (ans == n - 1) cout << sum << '\n';
	else cout << "orz\n";

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