#define _CRT_SECURE_NO_WARNINGS
#define itn int
#define PII pair<int, int>
#define PLI pair<long long, int>
#define fep(i,a,b) for(int i = (a); i >= (b); --i)
#define rep(i,a,b) for(int i = (a); i <= (b); ++i)
#include<bits/stdc++.h>
#include<unordered_map>
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
	/*求 m^k mod p，时间复杂度 O(logk)。
	m为底数，k为幂*/
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

unll n, m, k;

const int N = 1e4 + 5;
const ll INF = 1e9;
const ll MODE = ll(998244353);
const int dx[4] = { 1,-1, 0, 0 };
const int dy[4] = { 0, 0, 1,-1 };
priority_queue<unll, vector<unll>, greater<unll> >pq;

ll fa[N];
ll tp[N], bt[N];

struct Cir
{
	ll x, y, z;
}c[N];

bool cmp(Cir c1, Cir c2) {
	if (c1.x < c2.x) return 1;
	else if (c1.x == c2.x) {

		if (c1.y < c2.y) return 1;
		else if (c1.y == c2.y) {

			if (c1.z < c2.z)return 1;
		}
	}
	return 0;
}

ll findfa(ll k) {
	if (fa[k] == k) return k;
	else return fa[k] = findfa(fa[k]);
}
void addfa(ll x, ll y) {
	fa[findfa(x)] = findfa(y);
}

unll dis(ll x1, ll y1, ll z1, ll x2, ll y2, ll z2) {
	/*ll far = pow(x1 - x2, 2) + pow(y1 - y2, 2) + pow(z1 - z2, 2);
	return sqrt(far);*/
	return pow(x1 - x2, 2) + pow(y1 - y2, 2) + pow(z1 - z2, 2);
}


void solve() {

	ll h, r;
	cin >> n >> h >> r;

	rep(i, 1, n) fa[i] = i;

	rep(i, 1, n) cin >> c[i].x >> c[i].y >> c[i].z;

	int top = 0, buttom = 0;
	rep(i, 1, n) {
		if (c[i].z + r >= h)
			tp[++top] = i;
		if (c[i].z - r <= 0)
			bt[++buttom] = i;
	}

	//sort(c + 1, c + n + 1, cmp);

	if (n == 1) {
		if (c[1].z - r <= 0 && c[1].z + r >= h) {
			cout << "Yes\n";
			return;
		}
	}

	for (int i = 1; i < n; i++)
		for (int j = i + 1; j <= n; j++) {
			unll far = dis(c[i].x, c[i].y, c[i].z,/**/ c[j].x, c[j].y, c[j].z);
			if (far <= 4 * r * r) {
				ll x = findfa(i);
				ll y = findfa(j);
				//cout << "1\n";
				if (x != y) fa[x] = y;
				//addfa(i, j);
			}
		}

	/*cout << "*****  ";
	for (int i = 0; i <= n; i++) cout << fa[i] << ' ';
	cout << '\n';*/

	bool flag = 0;

	rep(i, 1, top) {
		rep(j, 1, buttom) {
			if (findfa(tp[i]) == findfa(bt[j])) {
				//cout << " *  " << fa[i] << ' ' << fa[j] << '\n';
				flag = 1;
				break;
			}
		}
		if (flag)break;
	}

	/*cout << "***   ";
	rep(i, 1, n) cout << fa[i] << ' ';
	cout << '\n';*/
	
	if (flag) cout << "Yes\n";
	else cout << "No\n";



	/*rep(i, 1, n) {
		if (c[i].z - r <= 0) {
			flag = 1;
			break;
		}
	}

	if (flag) {
		map<int, int>mp;
		rep(i, 1, n)
			mp[fa[i]]++;
		rep(i, 1, n) {
			if (mp[i] > 1 && c[i].z + r >= h) {
				cout << "Yes\n";
				return;
			}
		}
	}*/
	

	//cout << "No\n";

}



signed main() {
	std::ios::sync_with_stdio(false), std::cin.tie(0), std::cout.tie(0);
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