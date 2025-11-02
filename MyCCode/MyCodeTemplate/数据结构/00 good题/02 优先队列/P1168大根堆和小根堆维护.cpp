#define _CRT_SECURE_NO_WARNINGS
#define itn int
#define PII pair<int, int>
#define PLI pair<long long, int>
#define fep(i, a, b) for(int i = (a); i >= (b); --i)
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
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

const int N = 4e6 + 50;
const ll INF = 1e9;
const ll MODE = ll(998244353);
const int dx[4] = { 1,-1, 0, 0 };
const int dy[4] = { 0, 0, 1,-1 };
priority_queue<int> p;//这是一个大根堆q
//priority_queue<int, vector<int>, greater<int> >q;//这是一个小根堆q
priority_queue<ll, vector<ll>, greater<ll> >pq; // 小根


vector<ll>v;

void by_vector() {
	ll x;
	rep(i, 1, n) {
		cin >> x;

		//二分，查找第一个比x小的数
		v.insert(upper_bound(v.begin(), v.end(), x), x);

		if (i % 2 == 1) {
			cout << v[i - 1 >> 1] << '\n';
		}

	}
}

void by_priority_queue() {
	ll x; cin >> x;
	ll mid = x;
	cout << x << '\n';

	rep(i, 2, n) {
		cin >> x;

		if (x > mid) 
			pq.push(x); // 小根堆维护比mid大的数
		else 
			p.push(x);  // 大根堆维护比mid小的数

		if (i % 2 == 1) {
			while (pq.size() != p.size()) {
				if (pq.size() > p.size()) {
					p.push(mid);
					mid = pq.top(); pq.pop();
				}
				else if (pq.size() < p.size()) {
					pq.push(mid);
					mid = p.top(); p.pop();
				}
			}
			cout << mid << '\n';
		
		}
	}
}

void solve() {

	cin >> n;


	by_vector();
	by_priority_queue();
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