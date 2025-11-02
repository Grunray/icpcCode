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

string fir, mid, bck;

struct Node
{
	char val;
	Node* l;
	Node* r;
};

// 求后序遍历
void getPostOrder(int st_p, int ed_p, int st_s, int ed_s, Node*& p) {

	if (st_p > ed_p || st_s > ed_s) return;

	int i, j;
	for (i = st_p, j = st_s; i <= ed_p; i++, j++) {
		if (mid[j] == fir[st_p]) {
			break;
		}
	}

	p = new Node;

	p->l = p->r = NULL;

	p->val = fir[st_p];

	getPostOrder(st_p + 1,   i,  st_s, j - 1,  p->l);
	getPostOrder(i + 1,   ed_p, j + 1,  ed_s,  p->r);
	//cout << st_p << ' ' << ed_p << ' ' << st_s << ' ' << ed_s << '\n';
}

void DfsToPost(Node* p) {
	if (p == NULL) return;

	DfsToPost(p->l);
	DfsToPost(p->r);

	cout << p->val;
}
// 求前序遍历
void getPreOrder(int st_p, int ed_p, int st_s, int ed_s, Node*& p) {
	if (st_p > ed_p) return;

	int j;
	for (j = st_p; ; j++) {
		if (mid[j] == bck[ed_s]) {
			break;
		}
	}

	p = new Node;

	p->l = p->r = NULL;

	p->val = bck[ed_s];

	getPreOrder(st_p ,  j - 1,             st_s,  st_s + j - st_p - 1,  p->l);
	getPreOrder(j + 1,   ed_p,  st_s + j - st_p,             ed_s - 1,  p->r);
}

void DfsToPre(Node* p) {
	if (p == NULL) return;

	cout << p->val;

	DfsToPre(p->l);
	DfsToPre(p->r);

}

void solve() {

	cin >> mid >> bck;

	Node* root = NULL;

	//getPostOrder(0, mid.length() - 1, 0, fir.length() - 1, root);
	//DfsToPost(root);

	getPreOrder(0, mid.length() - 1, 0, bck.length() - 1, root);
	DfsToPre(root);

	cout << '\n';
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
