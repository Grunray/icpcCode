
/* 
	判断是否唯一， 如果题目没有说connected 联通，就要判断是否删除一条边之后会不会造成图不联通
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
const int N = 2e5 + 50;
const int M = 2e5 + 50;
const ll INF = 1e9;
const ll MODE = ll(998244353);
const int dx[4] = { 1,-1, 0, 0 };
const int dy[4] = { 0, 0, 1,-1 };
//priority_queue<int> p;//这是一个大根堆q
//priority_queue<int, vector<int>, greater<int> >q;//这是一个小根堆q
//priority_queue<ll, vector<ll>, greater<ll> >pq; // 小根

struct NODE
{
	int u, v, w;
	// 是否访问过、是否有相等权值的边、是否原本是生成树上的一条边然后删除了[前提是权值相同]
	bool vis = false, equal = false, del = false; 
}node[N];

bool cmp(NODE n1, NODE n2) {
	return n1.w < n2.w;
}

ll fa[N];
bool first; // 第一次访问的时候将vis赋值

ll findfa(int x) {
	if (x == fa[x])
		return x;
	else
		return fa[x] = findfa(fa[x]);
}

void addfa(int x, int y) {
	x = findfa(x); y = findfa(y);

	if (x == y) return;
	fa[x] = y;
}

int Kruskal() {

	//fill(fa, fa + n + m + 5, -1);
	rep(i, 1, n) fa[i] = i;

	ll res = 0; // 权值
	int tm = 0;
	rep(i, 1, m) {
		if (node[i].del) continue;
		if (tm == n - 1) break; // 如果 当前边 = 点数 - 1，无环图变数为 n - 1

		if (findfa(node[i].u) != findfa(node[i].v)) { // 如果两点没有访问过

			addfa(node[i].u, node[i].v);

			if(first) node[i].vis = true;

			res += node[i].w;
			tm++;
		}
	}
	return res;
}

bool connected() {
	//是否联通
	int num = findfa(fa[1]);
	int ans = 1;
	rep(i, 2, n) {
		if (num == findfa(fa[i]))
			ans++;
	}
	if (ans == n)// 联通
		return true;
	else //不联通
		return false;
}

void solve() {

	cin >> n >> m;

	if (n == 1 && m == 0) {
		cout << 0 << '\n';
		return;
	}

	rep(i, 1, m) {
		node[i].vis = false;
		node[i].equal = false;
		node[i].del = false;
	}

	rep(i, 1, m) cin >> node[i].u >> node[i].v >> node[i].w;

	sort(node + 1, node + m + 1, cmp);

	rep(i, 1, m - 1)
		if (node[i].w == node[i + 1].w)
			node[i].equal = true, node[i + 1].equal = true;

	rep(i, 1, n) fa[i] = i;

	//int tm = 0; // 记录当前有多少边已经连接

	first = 1;
	ll res = Kruskal();
	first = 0;

	rep(i, 1, m) {
		if (node[i].vis && node[i].equal) {// 如果这条边在初始的最小生成树中出现，并且是一条相等边
			node[i].del = true; // 删除这条边

			ll t = Kruskal();
			if (t == res) { //  如果权值相同

				//如果权值相同, 看是否联通
				//if (connected()) {
					cout << "Not Unique!\n";
					return;
				//}
				//else continue;
			}
			node[i].del = false; // 删除这条边之后，再将其加入，防止造成不联通
		}
	}

	cout << res << '\n';
	


}

signed main() {
	std::ios::sync_with_stdio(false); std::cin.tie(0), std::cout.tie(0);
	/*freopen("out.txt", "r", stdin);
	freopen("wrt.txt", "w", stdout);*/
	int TTT = 1; cin >> TTT;
	while (TTT--) {
		solve();
	}
	/*while (cin >> n >> m) {
		solve();
	}*/

	return 0;
}