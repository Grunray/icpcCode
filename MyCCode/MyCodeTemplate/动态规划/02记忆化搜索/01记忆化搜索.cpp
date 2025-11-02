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

/*
    如何写记忆化搜索
        方法一
            1把这道题的 dp 状态和方程写出来
            2根据它们写出 dfs 函数
            3添加记忆化数组
        方法二
            1写出这道题的暴搜程序（最好是 dfs）
            2将这个 dfs 改成「无需外部变量」的 dfs
            3添加记忆化数组
*/

const int N = 1e4 + 5;
const ll INF = 3e16;
const int MODE = 998244353;
unll n, m, k;
char ch;
ll res;
int state[N][N];// state[i][j]表示前i种花，在总采摘时间不超过j时，能获得的最大价值。

struct Flower
{
	int t, ans;
}f[N];
void dfs1(int pos, int cnt, int ttime) { //肯定超时

	if (ttime > n) return;

	if (pos == m + 1) {
		res = max(res, (ll)cnt);
		return;
	}
	// 每一朵花都有采和不采 这两种状态
	dfs1(pos + 1, cnt, ttime);
	dfs1(pos + 1, cnt + f[pos].ans, ttime + f[pos].t);
}

int dfs(int pos, int cnt) { //记忆化搜索

	if (state[pos][cnt] != -1) return state[pos][cnt];
	if (pos == m + 1) return state[pos][cnt] = 0;

	int t1, t2 = -INF;
	t1 = dfs(pos + 1, cnt);
	if (cnt >= f[pos].t)
		t2 = dfs(pos + 1, cnt - f[pos].t) + f[pos].ans;

	return state[pos][cnt] = max(t1, t2);
	
}

void solve() {

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

	//dfs(0, n);
	//dfs1(0, 0, 0);
	//cout << res;
}

signed main() {
	//IOS;
	//inout;
	int TTT = 1; //cin >> TTT;
	while (TTT--)
		solve();
	return 0;
}