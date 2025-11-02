#define PII pair<int, int>
#define frr for(int i = 0; i < n; i++)
#define frg for(register int i = 0; i < n; i++)
#define frp for(int i = 1; i <= n; i++)
#include<bits/stdc++.h>
using ll = long long;
using ldou = long double;
using unll = unsigned long long;
using namespace std;
int n, m, k;
string str;
const ll N = 2e5 + 5;
const ll MODE = 998244353;
//bool visit[N];
vector<int>v(N), fv(N);
map<int, PII>mp;
void solve() {

	cin >> n;

	frp cin >> v[i], fv[v[i]] = i;

	int ans = 0;
	frp
		if (v[i] != i) {
			mp[ans++] = { i, fv[i] };
			fv[v[i]] = fv[i];
			swap(v[i], v[fv[i]]);
		}
	cout << ans << '\n';
	for (int i = 0; i < ans; i++)
		cout << mp[i].first << ' ' << mp[i] .second<< '\n';

}
