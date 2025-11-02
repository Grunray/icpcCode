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
const int N = 1e5 + 5;
const ll INF = 0x3f3f3f3f;
const ll MODE = ll(1e6 + 7);

vector<bool> vis;
vector<vector<int> > adj;

int in[N];  // 存储每个结点的入度

bool toposort() {

	vector<int> L;
	queue<int> S;

	//预处理：把入度为0的点都放进去
	for (int i = 1; i <= n; i++)
		if (in[i] == 0) 
			S.push(i);

	while (!S.empty()) {
		int u = S.front(); S.pop();

		L.push_back(u);

		for (auto v : adj[u])
			if (--in[v] == 0) // 将当前点所有的出边的终点入度-1    如果 入度 = 0 则入队
				S.push(v);

	}

	if (L.size() == n) { // 当所有点都遍历了
		for (auto i : L) cout << i << ' ';
		return true;
	}
	else 
		return false;
}

void solve() {

	cin >> n >> m;

	adj.resize(n + 1);

	int u, v;
	rep(i, 1, m) {
		cin >> u >> v;
		adj[u].push_back(v);
		in[v]++;
	}
	
	toposort();

}
/*
7 10
1 2
3 2
1 4
2 5
4 5
2 6
4 6
3 7
5 7
6 7
*/

signed main() {
	std::ios::sync_with_stdio(false), std::cin.tie(0), std::cout.tie(0);
	//freopen("wrt.txt", "r", stdin); //freopen("out.txt", "w", stdout);
	int TTT = 1; //cin >> TTT;
	while (TTT--) {
		solve();
	}

	return 0;
}
