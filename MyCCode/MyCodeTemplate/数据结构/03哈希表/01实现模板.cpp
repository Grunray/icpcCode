
// 注释掉的是可以替换的部分

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
const ll MODE = ll(212370440130137957ll);
const unll base = 131;
const unll prime = 233317;
const int dx[4] = { 1,-1, 0, 0 };
const int dy[4] = { 0, 0, 1,-1 };
//priority_queue<unll, vector<unll>, greater<unll> >pq;

//unll res[N];
set<unll>res;

//核心部分
unll hashe(string s) {
	unll val = 0;

	for (int i = 0; i < s.length(); i++)
		val = (val * base + (unll)s[i]) % MODE + prime;

	return val;
}
/**/


void solve() {

	cin >> n;

	rep(i, 1, n) {
		cin >> str;
		res.insert(hashe(str));
		//res[i] = hashe(str);
	}

	//sort(res + 1, res + n + 1);

	/*ll cnt = 1;
	rep(i, 1, n - 1)
		if (res[i] != res[i + 1])
			cnt++;*/


	cout << res.size();

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