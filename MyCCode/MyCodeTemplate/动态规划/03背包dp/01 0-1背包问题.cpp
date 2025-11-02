//由于每个物体只有两种可能的状态（取与不取），对应二进制中的 0 和 1，这类问题便被称为「0-1 背包问题」

/*
例题中已知条件有第 i 个物品的重量 w[i]，价值 v[i]，以及背包的总容量 W。

设 DP 状态 f[i][j] 为在只能放前 i 个物品的情况下，容量为 j 的背包所能达到的最大总价值。
*//*
考虑转移。假设当前已经处理好了前 i-1 个物品的所有状态，那么对于第 i 个物品，当其不放入背包时，背包的剩余容量不变，
    背包中物品的总价值也不变，故这种情况的最大价值为 f[i - 1][j]；当其放入背包时，
    背包的剩余容量会减小 w[i]，背包中物品的总价值会增大 v[i]，故这种情况的最大价值为 f[i - 1][j - w[i]] + v[i]。

由此可以得出状态转移方程：
    f[i][j] = max(f[i - 1][j] , f[i - 1][j - w[i]] + v[i])
*//*
这里如果直接采用二维数组对状态进行记录，会出现 MLE。可以考虑改用滚动数组的形式来优化。
由于对 f[i] 有影响的只有 f_{i-1}，可以去掉第一维，直接用 f[i] 来表示处理到当前物品时背包容量为 i 的最大价值，得出以下方程：

****************************************************************
    f[j] = max(f[i], f[j - w[i]] + v[i]);
****************************************************************
    务必牢记并理解这个转移方程，因为大部分背包问题的转移方程都是在此基础上推导出来的。
*/

/*
常数优化：
	对于求sum可以用前缀和，这对于V比较大时是有用的。
具体代码：

	for (int i = 1; i <= n; i++) 
		cin >> v[i] >> w[i], 
			s[i] = s[i - 1] + v[i];
	for (int i = 1; i <= n; i++) {
		int bound = max(v[i], m - (s[n] - s[i]));
		for (int j = m; j >= bound; j--)
			f[j] = max(f[j], f[j - v[i]] + w[i]);
	}

*/

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

const int N = 1e4 + 5;
const ll INF = 3e16;
const int MODE = 998244353;
unll n, m, k;
int v[N], f[N], w[N];

void test01() {
	int W;
	//false 枚举顺序错了: j >= w[i]时出问题
	for (int i = 1; i <= n; i++)
		for (int l = 0; l <= W - w[i]; l++)
			f[l + w[i]] = max(f[l] + v[i], f[l + w[i]]);
	// 由 f[i][l + w[i]] = max(max(f[i - 1][l + w[i]], f[i - 1][l] + w[i]),
	// f[i][l + w[i]]); 简化而来
	//true
	for (int i = 1; i <= n; i++)
		for (int l = W; l >= w[i]; l--) f[l] = max(f[l], f[l - w[i]] + v[i]);
}
void solve1() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> w[i] >> v[i];
	for (int i = 1; i <= n; i++)
		for (int j = m; j >= w[i]; j--)
			f[j] = max(f[j], f[j - w[i]] + v[i]);
	cout << f[m];
}

void solve() {

}

signed main() {
	//IOS;
	//inout;
	int TTT = 1; //cin >> TTT;
	while (TTT--)
		solve();
	return 0;
}