
/*
    已知叶节点数据，求其他所有数据，从下往上建树
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

const int N = 1e6 + 50;
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
ll n, m, k;


struct Node
{
	ll val;
	ll l, r;
	int sign;
}child[N];


void bulti(ll depth) {

	if (depth <= 0) return;

	ll pos = pow(2, depth);
	ll st = pow(2, depth + 1);
	ll dif = pow(2, depth - 1);
	ll t = pos;
	rep(i, 0, dif + pos - 1) {
		// 父节点的标号为 pos 那么 两个子节点的标号为 pos * 2 和 pos * 2 + 1
		child[i + pos].l = st + pos * 2;
		child[i + pos].r = st + pos * 2 + 1;
		//child[i + pos].val = max(child[t * 2].val, child[t * 2 + 1].val);
		
		// 不会有平局 等号 = 无所谓
		if (child[t * 2].val >= child[t * 2 + 1].val) {
			child[i + pos].val = child[t * 2].val;
			child[i + pos].sign = child[t * 2].sign;
		}
		else {
			child[i + pos].val = child[t * 2 + 1].val;
			child[i + pos].sign = child[t * 2 + 1].sign;
		}
		t++;
		/*cout << "  dif + pos - 1  " << dif + pos - 1 << '\n';
		cout << "  i + pos " << i + pos << "   ";
		cout << "  st + pos * 2 " << st + pos * 2 << '\n';*/
	}

	//cout << "  pos st dif  " << pos << ' ' << st << ' ' << dif << '\n';
	//cout << '\n';
	bulti(depth - 1);
}

void solve() {

	cin >> n;

	ll st = pow(2, n);
	//cout << "  st  " << st << '\n';

	// 从最底层开始建树
	ll x;
	rep(i, 0, st - 1) {
		cin >> x;
		child[i + st].val = x;
		child[i + st].sign = i + 1;
		//cout << "  i + st  " << i + st << '\n';
	}
	//rep(i, 0, st - 1) {
	//	cout << child[i + st].sign << ' ';
	//	//cout << "  i + st  " << i + st << '\n';
	//}
	//cout << '\n';

	bulti(n - 1);

	/*rep(i, 0, (1 << (n + 1)) - 1)cout << child[i].val << ' ';
	cout << '\n';
	rep(i, 0, (1 << (n + 1)) - 1)cout << child[i].sign << ' ';
	cout << '\n';*/

	if (child[2].val > child[3].val)
		cout << child[3].sign;
	else
		cout << child[2].sign;



	//cout << min(child[2].val, child[3].val);

			
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
