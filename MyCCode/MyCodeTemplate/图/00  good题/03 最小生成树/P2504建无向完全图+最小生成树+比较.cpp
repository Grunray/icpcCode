
/*
	建立一个无向完全图，然后最小生成树生成一个数，看猴子跳跃的距离能不能大于最小生成树的所有边
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
const int N = 2e3 + 50;
const int M = 1e3 + 50;
const ll INF = 1e9;
const ll MODE = ll(998244353);
const int dx[4] = { 1,-1, 0, 0 };
const int dy[4] = { 0, 0, 1,-1 };
//priority_queue<int> p;//这是一个大根堆q
//priority_queue<int, vector<int>, greater<int> >q;//这是一个小根堆q
//priority_queue<ll, vector<ll>, greater<ll> >pq; // 小根

int monkey[M];
vector<PII>dis;
bool vis[N];
double d[N];

double graph[N][N];

double get_dis(int x1, int y1, int x2, int y2) {
	return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}

int MST(int v0) {

	int sum = 0; // 权值

	for (int i = 1; i <= n; i++)
		d[i] = graph[v0][i];

	vis[v0] = true;
	d[v0] = 0;

	for (int i = 1; i < n; i++) {

		double minn = INF;
		int pos = 0;

		for (int j = 1; j <= n; j++)
			if (minn > d[j] && !vis[j]) {
				minn = d[j];
				pos = j;
			}

		vis[pos] = true;
		sum += d[pos];

		for (int j = 1; j <= n; j++) // 往回找 
			if (graph[pos][j] < d[j] && !vis[j])
				d[j] = graph[pos][j];
	}

	return sum;
}


void solve() {

	cin >> m;

	rep(i, 1, m) {
		cin >> monkey[i];
		d[i] = monkey[i];
	}
	
	cin >> n;

	for (int i = 0; i <= n + 5; i++)
		for (int j = 0; j <= n + 5; j++)
			graph[i][j] = INF;

	dis.push_back({ 0,0 });
	int x, y;
	rep(i, 1, n) {
		cin >> x >> y;
		dis.push_back({ x + 1000, y + 1000 });
	}

	for (int i = 1; i < n; i++)
		for (int j = 1; j <= n; j++) {
			graph[i][j] = get_dis(dis[i].first, dis[i].second, dis[j].first, dis[j].second);
			graph[j][i] = graph[i][j];
		}

	MST(1);

	double maxn = 0;
	rep(i, 1, n)
		maxn = max(maxn, d[i]);

	int ans = 0;
	rep(i, 1, n)
		if ((double)monkey[i] >= maxn)
			ans++;

	cout << ans << '\n';

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