/*
    树状数组是一种支持 单点修改 和 区间查询 的，代码量小的数据结构。
*/

/*
    单点修改 和 区间查询 : 
        已知一个数列 a，你需要进行下面两种操作：

        给定 x, y，将 a[x] 自增 y。
        给定 l, r，求解 a[l...r] 的和。
            其中第一种操作就是「单点修改」，第二种操作就是「区间查询」。

        类似地，还有：「区间修改」、「单点查询」。它们分别的一个例子如下：

            区间修改：给定 l, r, x，将 a[l ... r] 中的每个数都分别自增 x；
            单点查询：给定 x，求解 a[x] 的值。
            注意到，区间问题一般严格强于单点问题，因为对单点的操作相当于对一个长度为 1 的区间操作。
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

const int N = 2e6 + 50;
const ll INF = 1e9;
const ll MODE = ll(998244353);
const int dx[4] = { 1,-1, 0, 0 };
const int dy[4] = { 0, 0, 1,-1 };
//priority_queue<int> p;//这是一个大根堆q
//priority_queue<int, vector<int>, greater<int> >q;//这是一个小根堆q
//priority_queue<ll, vector<ll>, greater<ll> >pq; // 小根

ll tree[N];

int lowbit(int x) {
	return x & (-x);
}

void addTree(int x, int k) { //在位置x加上k
    // 和x有关的都加
	while (x <= n) { // 下标从 1 - n
		tree[x] += k;
		x += lowbit(x); // 修改x之后，后面的和都要加
	}
}

int sumTree(int x) {
	int res = 0;
	while (x) {
		res += tree[x];
		x -= lowbit(x);
	}
	return res;
}

void solve() {

	cin >> n >> m;

	int x;
	rep(i, 1, n) {
		cin >> x;
		addTree(i, x);
	}

	int op, y;
	rep(i, 1, m) {
		cin >> op >> x >> y;

		if (op == 1)
			addTree(x, y); // 在x处加上y  将某一个数加上 x
		else if (op == 2)
			cout << sumTree(y) - sumTree(x - 1) << '\n'; // 求出某区间每一个数的和
	}
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