#define _CRT_SECURE_NO_WARNINGS
#define itn int
#define PII pair<int, int>
#define PLI pair<long long, int>
#define fep(i,a,b) for(int i = (a); i >= (b); --i)
#define rep(i,a,b) for(int i = (a); i <= (b); ++i)
#include<bits/stdc++.h>
using ll = long long;
using ldou = long double;
using unll = unsigned long long;
using namespace std;

ll gcd(ll a, ll b) { // 最大公约数
	while (b ^= a ^= b ^= a %= b)
		;
	return a;
}
ll lcm(ll a, ll b) { // 最小公倍数
	return a / gcd(a, b) * b;
}
ll qmi(ll m, ll k, ll p) { // 快速幂
	// 求 m^k mod p，时间复杂度 O(logk)。
	// m为底数，k为幂
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

//////////////////////////////////////////////////////////////////////////////////

unll n, m, k;
string str;
const int N = 5000;
const ll INF = 0x3f3f3f3f;
const ll MODE = ll(80112002);
const int dx[4] = { 1,-1, 0, 0 };
const int dy[4] = { 0, 0, 1,-1 };
//priority_queue<unll, vector<unll>, greater<unll> >pq;

int lenn, lenm;
char sq[N][N];
bool vis[N][N], mp[N][N];

bool dfs(int x, int y) {
	//if (/*vis[x][y] || */is) return;
	//vis[x][y] = true;
	//if (sq[x][y] == '.' &&
	//	((y == 0 || y == lenm - 1) && x >= n || x == lenn - 1) ) {
	//	is = true;
	//	return;
	//}
	//int nx, ny;
	//rep(i, 0, 3) {
	//	nx = x + dx[i];
	//	ny = y + dy[i];
	//	if (/*0 <= nx && nx < lenn && 0 <= ny && ny < lenm && */!vis[nx][ny] && sq[nx][ny] == '.') {
	//		/*nx %= n;
	//		ny %= m;*/
	//		/*if (nx >= n) {
	//			nx %= n;
	//		}
	//		if (nx < 0) {
	//			nx = n - 1;
	//		}
	//		if (ny >= m) {
	//			ny %= m;
	//		}
	//		if (ny < 0) {
	//			ny = m - 1;
	//		}*/
	//		dfs(nx, ny);
	//		vis[nx][ny] = false;
	//		/*if (nx == lenn - 1)
	//			dfs(0, ny);
	//		if (nx == 0)
	//			dfs(lenn - 1, ny);
	//		if (ny == lenm - 1)
	//			dfs(nx, 0);
	//		if (ny == 0)
	//			dfs(nx, lenm - 1);*/
	//	}
	//}

	if (x == -1) {
		if (dfs(lenn - 1, y))return true;
		return false;
	}
	if (x == lenn) {
		if (dfs(0, y))return true;
		return false;
	}
	if (y == -1) {
		if (dfs(x, lenm - 1))return true;
		return false;
	}
	if (y == lenm) {
		if (dfs(x, 0))return true;
		return false;
	}

	if (vis[x][y] || sq[x % n][y % m] == '#') return false;
	if (mp[x % n][y % m]) return true;

	vis[x][y] = true;
	mp[x % n][y % m] = true;

	/*rep(i, 0, 3) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (dfs(x + nx, y + ny)) 
			return true;
	}*/
	if (dfs(x + 1, y))return true;
	if (dfs(x - 1, y))return true;
	if (dfs(x, y + 1))return true;
	if (dfs(x, y - 1))return true;

	return false;
}

void solve() {

	cin >> n >> m;

	rep(i, 0, n - 1)
		rep(j, 0, m - 1)
			cin >> sq[i][j];

	/*cout << '\n';
	rep(i, 0, n - 1) cout << sq[i] << '\n';
	cout << '\n';*/

	//is = false;

	int q = 0, p = 0;
	rep(i, 0, n - 1) {
		rep(j, 0, m - 1)
			if (sq[i][j] == 'S') {
				p = i, q = j;
				//sq[i][j] = '.';
				break;
			}
		//if (p || q) break;
	}

	lenn = n * 2, lenm = m * 2;

	//for (int i = 0; i < n; i++) // 向右
	//	for (int j = 0; j < m; j++)
	//		sq[i][m + j] = sq[i][j];
	//for (int i = 0; i < n; i++) // 向下
	//	for (int j = 0; j < m; j++)
	//		sq[n + i][j] = sq[i][j];
	//for (int i = 0; i < n; i++) // 向右下
	//	for (int j = 0; j < m; j++)
	//		sq[n + i][m + j] = sq[i][j];
	//lenn = n * 2, lenm = m * 2;
	//for (int i = 0; i < n; i++) // 向右右
	//	for (int j = 0; j < m; j++)
	//		sq[i][lenm + j] = sq[i][j];
	//for (int i = 0; i < n; i++) // 向右下右
	//	for (int j = 0; j < m; j++)
	//		sq[n + i][lenm + j] = sq[i][j];
	//lenn = n * 2, lenm = m * 3;
	//sq[p][q] = 'O';
	//rep(i, 0, lenn - 1) {
	//	rep(j, 0, lenm - 1)
	//		cout << sq[i][j];
	//	cout << '\n';
	//}

	if (dfs(p, q)) cout << "Yes\n";
	else cout << "No\n";

	rep(i, 0, lenn - 1)
		rep(j, 0, lenm - 1)
			vis[i][j] = false;

	rep(i, 0, lenn - 1)
		rep(j, 0, lenm - 1)
			mp[i][j] = false;
	
	/*rep(i, 0, lenn - 1)
		rep(j, 0, lenm - 1)
			sq[i][j] = '#';*/

}

/*
5 5
#.#.#
.#.#.
S.#.#
.#.#.
#.#.#
8 7
..#.#..
.#..S##
#......
.#...#.
...#..#
...#...
#.#....
.#.##..
7 15
#..#.##.......#
#......#.####.#
#.#..#..##.#...
.###....#......
.....####...#..
.####.####.#..#
......#.##S#..#
8 9
###.#.#.#
#..S#.#.#
#.###.#.#
#.#...#.#
#.#.###.#
#.#.#...#
#.#.#.###
..#.#.#..
6 15
##.....#.###S..
...............
....#.##..##.##
...###.#....#..
###...#.#....#.
#..........##..

*/

signed main() {
	std::ios::sync_with_stdio(false), std::cin.tie(0), std::cout.tie(0);
	//freopen("wrt.txt", "r", stdin); //freopen("out.txt", "w", stdout);
	int TTT = 1; //cin >> TTT;
	while (TTT--) {
		solve();
	}
	/*while (cin >> n >> m) {
		solve();
	}*/

	return 0;
}