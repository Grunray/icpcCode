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
const int N = 1e4 + 50;
const int M = 2e5 + 50;
const ll INF = 5e5;
const ll MODE = ll(998244353);
const double Pi = 3.1415926;
const double eps = 1e-8;
const int dx[4] = { 1,-1, 0, 0 };
const int dy[4] = { 0, 0, 1,-1 };
//priority_queue<int> p;//这是一个大根堆q
//priority_queue<int, vector<int>, greater<int> >q;//这是一个小根堆q
//priority_queue<ll, vector<ll>, greater<ll> >pq; // 小根

ll dis[N][N], d[N];
bool vis[N]; //用于记录是否访问过这个节点

int Prim(int v0) {

	ll sum = 0; // 权值

	for (int i = 1; i <= n; i++)
		d[i] = dis[v0][i];

	vis[v0] = true;
	d[v0] = 0;

	for (int i = 1; i < n; i++) {

		ll minn = INF, pos = 0;

		for (int j = 1; j <= n; j++)
			if (minn > d[j] && !vis[j]) {
				minn = d[j];
				pos = j;
			}

		vis[pos] = true;
		sum += d[pos];

		// cout << "nowpos = " << pos << '\n';

		// for(int j = 1; j <= n; j++) {
		// 	cout << d[j] << ' ';
		// }
		// cout << '\n';

		for (int j = 1; j <= n; j++) // 往回找 
			if (dis[pos][j] < d[j] && !vis[j])
				d[j] = dis[pos][j];

		
	}

	return sum;
}


void solve() {

	cin >> n;
	int m; cin >> m;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			dis[i][j] = INF;

	/*ll u, v = 0, w;
	for (int i = 1; i <= n; i++) {
		cin >> w;
		u = i;
		dis[v][u] = dis[u][v] = w;
	}*/

	/*rep(i, 1, n)
		rep(j, 1, n)
		cin >> dis[i][j];*/

	int u, v, w;
	for (int i = 1; i <= m; i++) {
		cin >> u >> v >> w;
		if (w < dis[u][v])
			dis[v][u] = dis[u][v] = w;
	}
	
	ll res = Prim(1);

	for (int i = 1; i <= n; i++)
		if (!vis[i]) {
			cout << "orz";
			return;
		}

	cout << res;






	
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