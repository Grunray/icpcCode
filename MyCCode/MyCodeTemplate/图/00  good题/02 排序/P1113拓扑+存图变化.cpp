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

int w[N]; // 时间代价
int in[N];  // 存储每个结点的入度
// 用这两个变量来找时间不行的原因：
// 会重复计算某一个点的时间
int res, t; 
int fp[N];

bool toposort() {

	vector<int> L;
	queue<int> S;

	//预处理：把入度为0的点都放进去
	for (int i = 1; i <= n; i++)
		if (in[i] == 0) {
			//t = max(t, w[i]);
			S.push(i);
			fp[i] = w[i];
		}
	//res += t;
	//cout << t << '\n';
	//t = 0;
	while (!S.empty()) {
		int u = S.front(); S.pop();

		L.push_back(u);

		// 将当前点所有的出边的终点入度-1    如果 入度 = 0 则入队
		//for(itn i = 0; i < adj[u].size(); i++)
		for (auto v : adj[u]){
		//for (int i = 0; i < adj[u].size(); i++) {
			//int v = adj[u][i];
			if (--in[v] == 0) {
				//t = max(t, w[v]);
				S.push(v);
			}
			//将每个同一层的点 的花费同一为最大值
			fp[v] = max(fp[v], fp[u] + w[v]);
		}
		//res += t;
		//cout << t << '\n';
		//t = 0;
	}

	if (L.size() == n) { // 当所有点都遍历了
		/*for (auto i : L) cout << i << ' ';
		cout << '\n';*/
		return true;
	}
	else
		return false;
}

void solve() {

	cin >> n;

	adj.resize(n + 1);

	int u, v;
	rep(i, 1, n) {
		cin >> v >> w[i];

		while (cin >> u && u) {
			adj[u].push_back(v);
			in[v]++;
			m++; // 多少边
		}
	}

	/*for (int i = 1; i <= n; i++) {
		for (int j = 0; j < adj[i].size(); j++)
			cout << adj[i][j] << ' ';
		cout << '\n';
	}*/

	toposort();

	//cout << res << '\n';

	int cnt = 0;
	rep(i, 1, n) cnt = max(cnt, fp[i]);

	cout << cnt << '\n';
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
