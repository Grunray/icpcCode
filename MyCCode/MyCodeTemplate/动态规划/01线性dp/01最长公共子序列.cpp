#define _CRT_SECURE_NO_WARNINGS
#define IOS std::ios::sync_with_stdio(false), std::cin.tie(0), std::cout.tie(0);
#define inout freopen("wrt.txt", "r", stdin); freopen("out.txt", "w", stdout);
#define itn int
#define PII pair<int, int>
#define frr for(int i = 0; i < n; i++)
#define frg for(register int i = 0; i < n; i++)
#define frp for(int i = 1; i <= n; i++)
#define fgp for(int i = 0; i <= n; i++)
#include<bits/stdc++.h>
using ll = long long;
using ldou = long double;
using unll = unsigned long long;
using namespace std;

const int N = 1e5 + 5;
const ll INF = 3e16;
const int MODE = 998244353;
unll n, m, k;
int a[N], b[N], f[N];
map<int, int>mp;

//o(n^2)
int dp() {
	int f2[N][N];
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			if (a[i] == b[j])
				f2[i][j] = f2[i - 1][j - 1] + 1;
			else
				f2[i][j] = std::max(f2[i - 1][j], f2[i][j - 1]);

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++)
			cout << f2[i][j] << ' ';
		cout << '\n';
	}
		
	return f2[n][m];
}

//o(nlogn)
void solve() {

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		mp[a[i]] = i;
	}
	for (int i = 1; i <= n; i++) {
		cin >> b[i];
		f[i] = 0x7f7f7f7f;
	}

	int len = 0;
	f[0] = 0;
	for (int i = 1; i <= n; i++) {
		int l = 0, r = len, mid;

		if (mp[b[i]] > f[len])
			f[++len] = mp[b[i]];
		else {
			while (l < r) {
				mid = (l + r) / 2;
				if (f[mid] > mp[b[i]]) r = mid;
				else l = mid + 1;
			}
			f[l] = min(mp[b[i]], f[l]);
		}
	}
		
	cout << len;

}

signed main() {
	//IOS;
	//inout;
	int TTT = 1; //cin >> TTT;
	while (TTT--)
		solve();
	return 0;
}