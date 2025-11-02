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
string str, s2;
const int N = 1e5 + 5;
const ll INF = 4e18;
const ll MODE = ll(10000);
const int dx[4] = { 1,-1, 0, 0 };
const int dy[4] = { 0, 0, 1,-1 };
//priority_queue<unll, vector<unll>, greater<unll> >pq;

// *****单向链表*****
struct Singly_Node {
	int value;
	Singly_Node* next;
};
// 单向链表插入
void insertNode(int i, Singly_Node* p) {
	Singly_Node* node = new Singly_Node;
	node->value = i;
	node->next = p->next;
	p->next = node;
}
// 单向循环链表插入
void insertNode(int i, Singly_Node* p) {
	Singly_Node* node = new Singly_Node;
	node->value = i;
	node->next = NULL;
	if (p == NULL) {
		p = node;
		node->next = node;
	}
	else {
		node->next = p->next;
		p->next = node;
	}
}
// 单向循环链表删除
void deleteNode(Singly_Node* p) {
	p->value = p->next->value;
	Singly_Node* t = p->next;
	p->next = p->next->next;
	delete t;
}



// *****双向链表*****
struct Bidirectional_Node {
	int value;
	Bidirectional_Node* left;
	Bidirectional_Node* right;
};
// 双向循环链表插入
void insertNode(int i, Bidirectional_Node* p) {
	Bidirectional_Node* node = new Bidirectional_Node;
	node->value = i;
	if (p == NULL) {
		p = node;
		node->left = node;
		node->right = node;
	}
	else {
		node->left = p;
		node->right = p->right;
		p->right->left = node;
		p->right = node;
	}
}
// 双向循环链表删除
void deleteNode(Bidirectional_Node*& p) {
	p->left->right = p->right;
	p->right->left = p->left;
	Bidirectional_Node* t = p;
	p = p->right;
	delete t;
}

void solve() {



}

signed main() {
	std::ios::sync_with_stdio(false), std::cin.tie(0), std::cout.tie(0);
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