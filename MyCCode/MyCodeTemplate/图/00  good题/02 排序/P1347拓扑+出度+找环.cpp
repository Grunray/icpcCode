
//思路在csdn上
//https://blog.csdn.net/Grunray/article/details/140707454?spm=1001.2014.3001.5502

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

vector<vector<int> >adj;
//vector<bool>vis;
vector<int>t;
int in[N];
int out[N];

bool vis[30][30];
vector<PII>vp;
vector<int>res;
set<int>point;

int inn[N];

int cnt = 0;

int toposort() {

	cnt = 0;

	int t = 0;
	rep(i, 1, n)
		if (!out[i])
			t++;

	vector<int>L;
	queue<int>S;

	rep(i, 1, n) inn[i] = in[i];

	rep(i, 1, n) {
		if (!inn[i]) {
			S.push(i);
			cnt++;
			/*cout << "**********************\n";
			cout << "  i  " << i << '\n';*/
		}
		//cout << i << '\n';
	}

	while (!S.empty()) {

		int u = S.front(); S.pop();

		L.push_back(u);
		//L++;

		for (auto v : adj[u])
			if (!--inn[v]) {
				S.push(v);
				cnt++;
				//cout << "  i  " << v << ' ';
			}
	}

	/*cout << "----------\n";
	for (auto u : L) cout << u << ' ';
	cout << '\n';*/

	if (L.size() == n/*L == n*/ && t == 1) {
		/*for (int i = 0; i < L.size(); i++)
			res.push_back(L[i]);*/
		res = L;
		/*cout << "*********\n";
		for (auto u : L) cout << u << ' ';
		cout << '\n';*/
		return 1;
	}
	if (point.size() != cnt) return 2;

	//point.clear();
	return 0;
}

void solve() {

	cin >> n >> m;

	adj.resize(n + 5);
	vp.resize(m + 5);
	memset(in, -1, sizeof in);
	memset(out, -1, sizeof out);
	//vis.resize(n + 5, false);
	
	char x, y, ch;
	int u, v;
	//rep(i, 1, m) {
	//	cin >> x >> ch >> y;
	//	v = x - 'A' + 1;
	//	u = y - 'A' + 1;
	//	vp[i].first = u;
	//	vp[i].second = v;
	//	//cout << "  aaccc  \n";
	//}

	//////////

	rep(i, 1, m) {
		cin >> x >> ch >> y;

		if (x == y) {
			std::cout << "Inconsistency found after " << i << " relations.\n";
			return;
		}

		vp[i].first = x - 'A' + 1;
		vp[i].second = y - 'A' + 1;
	}

	rep(i, 1, m) {
		/*u = vp[i].first;
		v = vp[i].second;*/

		/*cin >> x >> ch >> y;

		u = x - 'A' + 1;
		v = y - 'A' + 1;*/

		u = vp[i].first;
		v = vp[i].second;

		point.insert(u);
		point.insert(v);

		//cout << "  u  v  " << u << ' ' << v << '\n';

		adj[u].push_back(v);
		if (in[u] == -1) in[u] = 0;
		if (in[v] == -1) in[v] = 0;
		//cout << "  ***  " << u << ' ' << v << '\n';
		in[v]++;

		if (out[u] == -1) out[u] = 0;
		if (out[v] == -1) out[v] = 0;
		out[u]++;
		//cout << "  ***  " << in[u] << ' ' << in[v] << '\n';

		/*cout << "  in  ";
		rep(i, 1, n) cout << in[i] << ' ';
		cout << '\n';*/

		/////////////////
		//check(u, v);

		if (toposort() == 1) {
			std::cout << "Sorted sequence determined after " << i << " relations: ";
			for (int j = 0; j < res.size(); j++)
				std::cout << char(res[j] - 1 + 'A');
			std::cout << ".\n";
			return;
		}
		else if (toposort() == 2) {
			std::cout << "Inconsistency found after " << i << " relations.\n";
			return;
		}
		//if (minn != 0x7777777) {
		//	ans = min(ans, i);
		//	/*cout << "****  " << minn << "\n";
		//	cout << "Inconsistency found after " << i << " relations.";*/
		//}
	}

	/*cout << "  in  ";
	rep(i, 1, n) cout << in[i] << ' ';
	cout << '\n';

	cout << "   adj   \n";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < adj[i].size(); j++)
			cout << adj[i][j] << ' ';
		cout << '\n';
	}*/

	//if (minn != 0x7777777 && !flag) {
	//	//ans = i;
	//	//cout << "****  " << minn << "\n";
	//	cout << "Inconsistency found after " << ans << " relations.";
	//	return;
	//}

	std::cout << "Sorted sequence cannot be determined.\n";

}

/*
4 4
A<B
A<C
B<C
C<D
*/

/*
4 6
C<D
C<B
B<A
C<D
D<A
A<A
*/

/*
4 4
A<B
B<C
C<A
B<B
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