#include<bits/stdc++.h>
using ll = long long;
using ldou = long double;
using unll = unsigned long long;
using namespace std;

unll n, m, k;

//线性dp
void t_01_01() {//最长公共子序列
    const int N = 1e5 + 5;
    int a[N], b[N], f[N];
    map<int, int>mp;

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
void t_01_02() {//最长不下降子序列
    const int N = 1e5 + 5;
    int d[N], a[N];
    d[1] = a[1];
	int len = 1;

	for (int i = 2; i <= n; i++) {
		if (a[i] > d[len]) { // 不降序改为 >= 
			cout << "   a[i] > d[len]   \n";
			d[++len] = a[i];
			for (int i = 1; i <= len; i++) cout << d[i] << ' ';
			cout << '\n';
		}
		else {
			cout << "  ******   \n";
			int t = lower_bound(d + 1, d + len + 1, a[i]) - d/*-d获得索引*/;  // 不降序改为upper_bound
			d[t] = a[i];
			for (int i = 1; i <= len; i++) cout << d[i] << ' ';
			cout << '\n';
		}
	}
	for (int i = 1; i <= len; i++) cout << d[i] << ' ';
	cout << '\n';

	cout << len;
}

//记忆化搜索
void t_02_01() {//记忆化搜索
    const int N = 1e4 + 5;
    int state[N][N];
    struct Flower
    {
        int t, ans;
    }f[N];

    cin >> n >> m;

	for (int i = 1; i <= m; i++) cin >> f[i].t >> f[i].ans;

	for(int i = 1; i <= m; i++) 
		for (int j = 0; j <= n; j++) {
			state[i][j] = state[i - 1][j]; //表示不选择当前这种花时的情况
			if (j >= f[i].t) // 判断当前的采摘时间j大于等于当前花的采摘时间f[i].t时，说明可以选择当前花进行采摘。
				state[i][j] = max(state[i][j], state[i - 1][j - f[i].t] + f[i].ans);//通过判断j是否大于等于当前花的采摘时间f[i].t，
                                        //如果是，则尝试选择当前花，更新state[i][j]为选择当前花和不选择当前花中较大的那个。
                                        //选取当前花：此时需要考虑前i-1种花在总采摘时间不超过j - f[i].t时能获得的最大价值（即state[i-1][j - f[i].t]），
                                        //再加上当前花的价值f[i].ans，得到在总采摘时间不超过j时能获得的最大价值。
		}

	cout << state[m][n];
}

//背包dp   
 //f[i][j] = max(f[i - 1][j] , f[i - 1][j - w[i]] + v[i])
 //f[j] = max(f[i], f[j - w[i]] + v[i]);
void t_03_01() {//01背包
    //f[j] = max(f[j], f[j - w[i]] + v[i]);
    const int N = 1e4 + 5;
    int v[N], f[N], w[N];
    cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> w[i] >> v[i];
	for (int i = 1; i <= n; i++)
		for (int j = m; j >= w[i]; j--)
			f[j] = max(f[j], f[j - w[i]] + v[i]);
	cout << f[m];
}
void t_03_02() {//完全背包
    //f[i][j] = max(f[i - 1][j], f[i][j - w[i]] + v[i])

    const int N = 1e5 + 5;
    ll v[N], f[(unll)1e7 + 5], w[N];
    
    cin >> m >> n;

    for (int i = 1; i <= n; i++) cin >> w[i] >> v[i];

    for (int i = 1; i <= n; i++)
        for (int j = w[i]; j <= m; j++)
            f[j] = max(f[j], f[j - w[i]] + v[i]);

    cout << f[m];
}


void solve() {

}

signed main() {
    std::ios::sync_with_stdio(false), std::cin.tie(0), std::cout.tie(0);//IOS;
	int TTT = 1; //cin >> TTT;
	while (TTT--)
		solve();
	return 0;
}