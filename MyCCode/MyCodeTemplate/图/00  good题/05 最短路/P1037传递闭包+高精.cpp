/*
*我的代码可能会wa，但是我的篮球永不会输
*⠀⠀⠀⠀⠰⢷⢿⠄
*⠀⠀⠀⠀⠀⣼⣷⣄
*⠀⠀⣤⣿⣇⣿⣿⣧⣿⡄
*⢴⠾⠋⠀⠀⠻⣿⣷⣿⣿⡀
*🏀⠀⢀⣿⣿⡿⢿⠈⣿
*⠀⠀⠀⢠⣿⡿⠁⠀⡊⠀⠙
*⠀⠀⠀⢿⣿⠀⠀⠹⣿
*⠀⠀⠀⠀⠹⣷⡀⠀⣿⡄
*⠀⠀⠀⠀⣀⣼⣿⠀⢈⣧
*⠀⠀⠀⠀只因你太美
*/

/*
    // 传递性
	// 因为可能会有 1->2 2->3情况存在
    // 用弗洛伊德算法 找到一个数字可以变化的次数和
    // 之后在连续乘起来 得到的结果就是变化次数
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

ll n, m;
const int N = 1000010;
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

string str;
int f[15][15];
int d[15];
int p[1005];

void solve() {

	cin >> str >> n;

	int u, v;
	rep(i, 1, n) {
		cin >> u >> v;
		f[u][v] = 1;
	}

	// 传递性
	// 因为可能会有 1->2 2->3情况存在
    // 用弗洛伊德算法 找到一个数字可以变化的次数和
    // 之后在连续乘起来 得到的结果就是变化次数
	rep(k, 0, 9) rep(i, 0, 9) rep(j, 0, 9)
		if (f[i][k] && f[k][j])
			f[i][j] = 1;
	/*rep(k, 0, 9) rep(i, 0, 9) rep(j, 0, 9)
		cout << "  i  k  k  j  " << i << ' ' << k << ' ' << k << ' ' << j << '\n';*/

	rep(i, 0, 9) {
		f[i][i] = 1;

		rep(j, 0, 9)
			if (f[i][j])
				d[i]++;
	}

	/*rep(i, 0, 9) {
		cout << "  i  " << i << "   ";
		rep(j, 0, 9)
			cout << f[i][j] << ' ';
		cout << '\n';
	}*/

	/*rep(i, 0, 9)
		cout << d[i] << ' ';
	cout << '\n';*/


	int z = 0;
	p[0] = 1;
	int x;
	for (int i = 0; str[i]; i++) {

		z = 0;
		x = d[str[i] - '0'];

		//高精
		for (int j = 0; j < 500; j++) {
			p[j] = p[j] * x + z;
			z = p[j] / 10;
			p[j] %= 10;
		}
	}

	int i = 500;
	while (p[i] == 0) i--;

	while (0 <= i) cout << p[i--];



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
/*
⣿⣿⣿⠟⠛⠛⠻⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡟⢋⣩⣉⢻⣿⣿⣿
⣿⣿⣿⠀⣿⣶⣕⣈⠹⠿⠿⠿⠿⠟⠛⣛⢋⣰⠣⣿⣿⠀⣿⣿⣿
⣿⣿⣿⡀⣿⣿⣿⣧⢻⣿⣶⣷⣿⣿⣿⣿⣿⣿⠿⠶⡝⠀⣿⣿⣿
⣿⣿⣿⣷⠘⣿⣿⣿⢏⣿⣿⣋⣀⣈⣻⣿⣿⣷⣤⣤⣿⡐⢿⣿⣿
⣿⣿⣿⣿⣆⢩⣝⣫⣾⣿⣿⣿⣿⡟⠿⠿⠦⠀⠸⠿⣻⣿⡄⢻⣿
⣿⣿⣿⣿⣿⡄⢻⣿⣿⣿⣿⣿⣿⣿⣿⣶⣶⣾⣿⣿⣿⣿⠇⣼⣿
⣿⣿⣿⣿⣿⣿⡄⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡟⣰⣿
⣿⣿⣿⣿⣿⣿⠇⣼⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⢀⣿⣿
⣿⣿⣿⣿⣿⠏⢰⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⢸⣿⣿
⣿⣿⣿⣿⠟⣰⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠀⣿⣿
⣿⣿⣿⠋⣴⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡄⣿⣿
⣿⣿⠋⣼⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡇⢸⣿
*/