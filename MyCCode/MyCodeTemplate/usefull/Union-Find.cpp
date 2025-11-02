#define frr for(int i = 0; i < n; i++)
#define frg for(register int i = 0; i < n; i++)
#define frp for(int i = 1; i <= n; i++)
#include<bits/stdc++.h>
using ll = long long;
using ldou = long double;
using unll = unsigned long long;
using namespace std;

int n, m;
string str;
const ll N = 2e5 + 5;
const ll MODE = 998244353;
int fa[N];
map<ll, ll>mp;

int findfa(int k) {
	if (fa[k] == k)
		return k;
	else 
		return fa[k] = findfa(fa[k]);
}

void addfa(int x, int y) {
	fa[findfa(x)] = findfa(y);
}

void solve() {

	cin >> n >> m;

	frp fa[i] = i;

	int a, b;
	for (int i = 1; i <= m; i++) {
		cin >> a >> b;
		addfa(a, b);
	}
	frp mp[findfa(i)]++;

	ll res = 0;
	for (int i = 0; i < mp.size(); i++)
		res += 1.0 * mp[i] * (mp[i] - 1) / 2;
	std::cout << res - m;
}