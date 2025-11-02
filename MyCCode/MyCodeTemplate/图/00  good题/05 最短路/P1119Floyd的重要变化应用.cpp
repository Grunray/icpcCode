#include<bits/stdc++.h>
using namespace std;

//#define int long long

#define bit(x) (1LL << (x))
#define lowbit(x) (x & -x)
#define sq(x) ((x) * (x))

#define rep(a, b, c, d) for (int a = (b); a <= (c); a += (d))
#define fep(a, b, c, d) for (int a = (b); a >= (c); a -= (d))

using unll = unsigned long long;
using ll = long long;

/*--fast read--*/
template<typename T> T read() {
	T X = 0; bool flag = true; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') flag = false; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { X = (X << 1) + (X << 3) + ch - '0'; ch = getchar(); }
	if (flag) return X;
	return ~(X - 1);
}
template<typename T> void write(T X) {
	if (X < 0) { putchar('-'); X = ~(X - 1); }
	int s[100], top = 0;
	while (X) { s[++top] = X % 10; X /= 10; }
	if (!top) s[++top] = 0;
	while (top) putchar(s[top--] + '0');
}
/*--const--*/
const int INF = 0x3f3f3f3f;
const long long LINF = 0x3f3f3f3f3f3f3f3f;
const long long MODE = 998244353;

const int dx[] = { 1, 0,-1, 0,   1, 1,-1,-1 };
const int dy[] = { 0,-1, 0, 1,  -1, 1,-1, 1 };

const double eps = 1e-8;
double Pi = acos(-1.0);
/*--math--*/
long long qpow(long long x, long long y) {
	x %= MODE;
	long long res = 1;
	while (y) {
		if (y & 1) res = res * x % MODE;
		x = x * x % MODE;
		y >>= 1;
	}
	return res;
}
long long gcd(long long a, long long b) { // 最大公约数
	while (b ^= a ^= b ^= a %= b)
		;
	return a;
}
long long lcm(long long a, long long b) { // 最小公倍数
	return a / gcd(a, b) * b;
}

/*------------CODE------------*/

// int months[15] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };

//priority_queue<ll> pq;//这是一个大根堆q
//priority_queue<int, vector<int>, greater<int> >q;//这是一个小根堆q
//priority_queue<ll, vector<ll>, greater<ll> >pq; // 小根

const long long N = 2e5 + 50;
const long long M = 2e6 + 50;

ll n, m;

ll f[250][250];

ll tim[250];

void solve() {

	cin >> n >> m;

	rep(i, 0, n - 1, 1) cin >> tim[i];

	rep(i, 0, n + 5, 1)
		rep(j, 0, n + 5, 1)
			if (i == j)
				f[i][j] = 0;
			else
				f[i][j] = INF;


	ll u, v, w;
	rep(i, 1, m, 1) {
		cin >> u >> v >> w;
		f[u][v] = w;
		f[v][u] = w;
	}

	// rep(k, 0, n - 1, 1)
	// 	rep(i, 0, n - 1, 1)
	// 		rep(j, 0, n - 1, 1)
	// 			f[i][j] = min(f[i][j], f[i][k] + f[k][j]);

	ll q; cin >> q;
	ll k = 0;
	while (q--) {
		cin >> u >> v >> w;

		while (tim[k] <= w && k < n) {
			rep(i, 0, n - 1, 1)
				rep(j, 0, n - 1, 1)
					f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
			k++;
			//cout << "  k  " << k << '\n';
		}

		if (tim[u] > w || tim[v] > w || f[u][v] == INF) {
			cout << -1 << '\n';
			continue;
		}



		cout << f[u][v] << '\n';

	}


}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	//freopen("wrt.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);

	signed T = 1;
	//cin >> T;
	while (T--) {
		solve();
	}
}