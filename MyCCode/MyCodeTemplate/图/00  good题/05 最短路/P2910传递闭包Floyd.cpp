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

ll need[M];
ll f[N][N];

void solve() {

	cin >> n >> m;

	//相当于要从need[i] -> need[i + 1]   i from 1 to m - 1
	rep(i, 1, m)
		cin >> need[i];

	rep(i, 1, n)
		rep(j, 1, n)
			cin >> f[i][j];

	rep(k, 1, n)
		rep(i, 1, n)
			rep(j, 1, n)
				f[i][j] = min(f[i][j], f[i][k] + f[k][j]); // i -> j的最短路长为min(...)

	ll res = 0;
	ll u, v;
	rep(i, 1, m - 1) {
		u = need[i], v = need[i + 1];
		res += f[u][v];
	}

	cout << res << '\n';

	



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