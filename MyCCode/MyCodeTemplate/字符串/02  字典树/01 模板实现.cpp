#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;

//#define int long long

#define bit(x) (1LL << (x))
#define lowbit(x) (x & -x)
#define sq(x) ((x) * (x))

#define rep(a, b, c, d) for (int a = (b); a <= (c); a += (d))
#define fep(a, b, c, d) for (int a = (b); a >= (c); a -= (d))

#define PLL pair<long, long>

using unll = unsigned long long;
using ll = long long;

/*--fast read--*/
// use : n = read<int>();
template<typename T> T read() {
	T X = 0; bool flag = true; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') flag = false; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { X = (X << 1) + (X << 3) + ch - '0'; ch = getchar(); }
	if (flag) return X;
	return ~(X - 1);
}
// 毒瘤 只能Linux上用 win上报错
//template<typename T> T read() {
//	T X = 0; bool flag = true; char ch = getchar_unlocked(); // 比getchar还快
//	while (ch < '0' || ch > '9') { if (ch == '-') flag = false; ch = getchar_unlocked(); }
//	while (ch >= '0' && ch <= '9') { X = (X << 1) + (X << 3) + ch - '0'; ch = getchar_unlocked(); }
//	if (flag) return X;
//	return ~(X - 1);
//}
// use : write<ll>(n);
template<typename T> void write(T X) {
	if (X < 0) { putchar('-'); X = ~(X - 1); }
	int s[100], top = 0;
	while (X) { s[++top] = X % 10; X /= 10; }
	if (!top) s[++top] = 0;
	while (top) putchar(s[top--] + '0');
}
/*--const--*/
const int INF = 0x3f3f3f3f;
const long long LINF = 0x3f3f3f3f3f3f3f3f;
const long long MODE = 998244353;

const int dx[] = { 1, 0,-1, 0,   1, 1,-1,-1 };
const int dy[] = { 0,-1, 0, 1,  -1, 1,-1, 1 };

const double eps = 1e-8;
double Pi = acos(-1.0);
/*--math--*/
long long qpow(long long x, long long y) {
	x %= MODE;
	long long res = 1;
	while (y) {
		if (y & 1) res = res * x % MODE;
		x = x * x % MODE;
		y >>= 1;
	}
	return res;
}
long long gcd(long long a, long long b) { // 最大公约数
	while (b ^= a ^= b ^= a %= b)
		;
	return a;
}
long long lcm(long long a, long long b) { // 最小公倍数
	return a / gcd(a, b) * b;
}

/*------------CODE------------*/

// int months[15] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };

//priority_queue<ll> pq;//这是一个大根堆q
//priority_queue<int, vector<int>, greater<int> >q;//这是一个小根堆q
//priority_queue<ll, vector<ll>, greater<ll> >pq; // 小根
const long long N = 1e4 + 50;
const long long M = 2e6 + 50;

ll n, m;

struct Node {
	int cnt;
	unordered_map<char, Node*> ch;

	Node() : cnt(0) {};

	void dfs() {
		for (auto it : ch) {
			it.second->dfs();
			cnt += it.second->cnt;
		}
	}

	void bulit(string &str, Node* u) {
		for (auto c : str) {
			if (u->ch[c] == NULL)
				u = u->ch[c] = new Node;
			else
				u = u->ch[c];
		}
		++u->cnt;
	}

	int find(string& str, Node* u) {
		bool flag = true;
		for (auto c : str) {
			if (u->ch[c] != NULL)
				u = u->ch[c];
			else {
				flag = false;
				break;
			}
		}
		if (flag) return u->cnt;
		else return 0;
	}
}*root;

string str;

void solve() {

	ll q;
	cin >> n >> q;

	root = new Node();
	auto u = root;
	rep(i, 1, n, 1) {
		cin >> str;

		u = root;

		root->bulit(str, u);
	}

	root->dfs();

	bool flag = true;
	rep(i, 1, q, 1) {
		cin >> str;

		u = root;

		cout << root->find(str, u) << '\n';
	}



}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	//freopen("wrt.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);

	int T = 1;
	cin >> T;
	while (T--) {
		solve();
	}
}