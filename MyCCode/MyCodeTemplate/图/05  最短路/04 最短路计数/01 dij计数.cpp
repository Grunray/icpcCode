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
const int M = 4e6 + 50;
const ll INF = 0x3f3f3f3f;
const ll MODE = ll(100003);
const double Pi = 3.1415926;
const double eps = 1e-8;
const int dx[4] = { 1,-1, 0, 0 };
const int dy[4] = { 0, 0, 1,-1 };
//priority_queue<ll> pq;//这是一个大根堆q
//priority_queue<int, vector<int>, greater<int> >q;//这是一个小根堆q
priority_queue<ll, vector<ll>, greater<ll> >pq; // 小根
ll n, m, k;


struct Edge
{
	ll u, v, w, next;
}e[M];

ll head[N], cnt, s, vis[N], dis[N];
ll ed[M];
bool rev[N];

struct node
{
	ll w, now;
	inline bool operator <(const node& x)const
	{
		return w > x.w;
	}
};

priority_queue<node>q;

inline void add(ll u, ll v, ll w = 1)
{
	e[++cnt].u = u;
	e[cnt].v = v;
	e[cnt].w = w;
	e[cnt].next = head[u];
	head[u] = cnt;
}

void dijkstra()
{
	for (int i = 1; i <= n; i++)
	{
		dis[i] = INF;
	}
	dis[s] = 0;
	ed[1] = 1;

	q.push({ 0, s });
	while (!q.empty())
	{
		node x = q.top();
		q.pop();
		ll u = x.now;
		if (vis[u]) continue;

		vis[u] = 1;
		for (int i = head[u]; i; i = e[i].next)
		{
			ll v = e[i].v;
			/*if (u == v) {
				if (!rev[u]) {
					ed[u] = 1;
					rev[u] = true;
				}
				else 
					ed[u]++;
				q.push({ dis[v], v });
				continue;
			}*/
			if (dis[v] == dis[u] + /*e[i].w*/ 1)
			{
				ed[v] += ed[u];
				ed[v] %= MODE;
			}
			if (dis[v] > dis[u] + /*e[i].w*/ 1)
			{
				ed[v] = ed[u];
				dis[v] = dis[u] + e[i].w;
				q.push({ dis[v], v });
			}
		}
	}
}

void solve() {

	n = read(), m = read();
	//s = read();
	s = 1;
	for (int i = 1, x, y, z; i <= m; i++)
	{
		x = read(), y = read()/*, z = read()*/;
		//if (x == y) ed[x] += 1;
		// 处理自环
		if (x == y) continue;
		add(x, y/*, z*/);
		add(y, x/*, z*/);
	}
	dijkstra();
	/*for (int i = 1; i <= n; i++)
		cout << dis[i] << ' ';
	cout << '\n';*/

	rep(i, 1, n)
		cout << ed[i] << '\n';
	//cout << '\n';

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
