
//因为有重边，所以从邻接表改成邻接矩阵

//可以实现拓扑后将层级分出

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
const int N = 1005;
const ll INF = 0x3f3f3f3f;
const ll MODE = ll(80112002);
const int dx[4] = { 1,-1, 0, 0 };
const int dy[4] = { 0, 0, 1,-1 };
//priority_queue<unll, vector<unll>, greater<unll> >pq;

//vector<vector<int> >adj;
int adj[N][N];
vector<bool>vis;
vector<int>t;
int in[N];
//int out[N];
int ranks[N];

bool toposort() {

	//vector<int>L;
	int L = 0;
	queue<int>S;

	rep(i, 1, n)
		if (!in[i]) {
			S.push(i);
			ranks[i] = 1;
		}


	while (!S.empty()) {

		int u = S.front(); S.pop();

		//L.push_back(u);
		L++;

		//for (auto v : adj[u])
		for (int i = 1; i <= n; i++) {
			int v = adj[u][i];
			if(adj[u][i])
				if (!--in[i]) {
					S.push(i);
					ranks[i]++;
					ranks[i] += ranks[u];
				}
		}
			
		/*for (int i = 0; i < adj[u].size(); i++) {
			int v = adj[u][i];
			if (!--in[v]) {
				S.push(v);
                ranks[v]++;
				ranks[v]+= ranks[u];
			}
		}*/
	}

	if (/*L.size()*/L == n) {
		/*for (auto u : L) cout << u << ' ';
		cout << '\n';*/
		return true;
	}

	return false;
}

void solve() {

	cin >> n >> m;

	//adj.resize(n + 5);
	t.resize(n + 5);
	vis.resize(n + 5, false);

	//int u, v;
	//rep(i, 1, m) {
	//	cin >> x;
	//	rep(j, 1, x) {
	//		cin >> v;
	//		//adj[i].push_back(v);
	//		//in[v]++;
	//	}
	//}

	int x, y;
	for (int i = 1; i <= m; i++) {
		cin >> x;
		for (int j = 0; j < x; j++) {
			cin >> t[j];
			vis[t[j]] = true;
		}
		/*for (int j = 1; j <= n; j++) {
			if (!is[j]) {
				for (int q = 1; q <= n; q++)
					if (q != j && is[q])
						adj[q].push_back(j);
			}
		}
		fill(is.begin(), is.begin() + n + 1, false);*/
		for (int v = t[0]; v < t[x - 1]; v++) {
			if (!vis[v])
				for (int u = 0; u < x; u++)
					if (/*u != v && *//*vis[u]*/!adj[v][t[u]]) {
						adj[v][t[u]] = 1;
						//adj[u].push_back(v);
						in[t[u]]++;
						//out[u]++;
					}
		}
		fill(vis.begin(), vis.begin() + n + 1, false);
	}



	/*cout << "*******\n";
	for (int i = 1; i <= n; i++) {
		cout << " i " << i << "  ";
		for (int j = 0; j < adj[i].size(); j++)
			cout << adj[i][j] << ' ';
		cout << '\n';
	}
	cout << "*******\n";*/

	toposort();

	/*for (int i = 1; i <= n; i++)
		cout << ranks[i] << ' ';*/

	/*for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			cout << rec[i][j] << ' ';
		cout << '\n';
	}*/
		

	ll res = 0;
	rep(i, 1, n)
		res = max(res, (ll)ranks[i]);

	cout << res;

}

/*
6 1
4 1 3 5 6
*/

signed main() {
	//std::ios::sync_with_stdio(false), std::cin.tie(0), std::cout.tie(0);
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