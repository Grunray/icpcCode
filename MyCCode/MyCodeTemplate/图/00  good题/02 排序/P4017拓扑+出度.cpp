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
const int N = 5e5 + 5;
const ll INF = 0x3f3f3f3f;
const ll MODE = ll(80112002);
//priority_queue<unll, vector<unll>, greater<unll> >pq;

vector<vector<ll> > adj;
vector<bool>vis;
ll in[N], out[N];
ll fp[N];

bool toposort() {

	vector<ll>L;
	queue<ll>S;

	rep(i, 1, n) 
		if (!in[i]) {
			S.push(i);
			fp[i] = 1;
		}

	while (!S.empty()) {

		ll u = S.front(); S.pop();

		L.push_back(u);

		for (auto v : adj[u]) {
			fp[v] = (fp[v] + fp[u]) % MODE;
			if (!--in[v]) {
				S.push(v);
			}
				
		}
	}

	if (L.size() == n) {
		/*for (auto u : L) cout << u << ' ';
		cout << '\n';*/
		return true;
	}
	else return false;
}

void solve() {

	cin >> n >> m;

	adj.resize(n + 1);
	vis.resize(n + 1, false);

	ll u, v;
	rep(i, 1, m) {
		cin >> u >> v;

		adj[u].push_back(v);
		in[v]++;
		out[u]++;
	}

	toposort();

	ll res = 0;
	rep(i, 1, n) if (!out[i]) res = (res + fp[i]) % MODE;

	cout << res << endl;


}

signed main() {
	std::ios::sync_with_stdio(false), std::cin.tie(0), std::cout.tie(0);
	//freopen("wrt.txt", "r", stdin); //freopen("out.txt", "w", stdout);
	int TTT = 1; //cin >> TTT;
	while (TTT--) {
		solve();
	}

	return 0;
}
