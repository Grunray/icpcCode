//**********并查集**********
//
/*
input
4 3
1 2
2 3
1 4
output
3
*/
#define _CRT_SECURE_NO_WARNINGS
#define IOS std::ios::sync_with_stdio(false), std::cin.tie(0), std::cout.tie(0);
#define inout freopen("wrt.txt", "r", stdin); freopen("out.txt", "w", stdout);
#define itn int
#define PII pair<int, int>
#define frr for(int i = 0; i < n; i++)
#define frg for(register int i = 0; i < n; i++)
#define frp for(int i = 1; i <= n; i++)
#define INF 10000000
#include<bits/stdc++.h>
using ll = long long;
using ldou = long double;
using unll = unsigned long long;
using namespace std;

//map<string, int>mp;
//stack<int>st;
//queue<int>q;
//set<int>s;
//priority_queue<unll, vector<unll>, greater<unll> >pq;
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

signed main() {
	IOS;
	//inout;
	int TTT = 1; //cin >> TTT;
	while (TTT--)
		solve();
	return 0;
}