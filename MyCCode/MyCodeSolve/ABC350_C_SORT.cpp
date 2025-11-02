//**********插入排序**********
//
/*
input
5
3 4 1 2 5
output
2
1 3
2 4
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
	/*cout << '\n';
	frp cout << v[i] << ' ';*/
}

signed main() {
	IOS;
	//inout;
	int TTT = 1; //cin >> TTT;
	while (TTT--)
		solve();
	return 0;
}