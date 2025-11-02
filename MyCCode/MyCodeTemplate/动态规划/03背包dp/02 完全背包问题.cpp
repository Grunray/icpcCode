/*完全背包模型与 0-1 背包类似，与 0-1 背包的区别仅在于一个物品可以选取无限次，而非仅能选取一次。*/

/*
我们可以借鉴 0-1 背包的思路，进行状态定义：设 f[i][j] 为只能选前 i 个物品时，容量为 j 的背包可以达到的最大价值。
需要注意的是，虽然定义与 0-1 背包类似，但是其状态转移方程与 0-1 背包并不相同。
*/

/*
可以考虑一个朴素的做法：对于第 i 件物品，枚举其选了多少个来转移。这样做的时间复杂度是 O(n^3) 的。
    状态转移方程如下：
        f[i][j] = max(f[i - 1][j - k * w] + v[i] * k)  f from 0 to +oo

考虑做一个简单的优化。可以发现，对于 f_{i,j}，只要通过 f_{i,j-w_i} 转移就可以了。
    因此状态转移方程为：
        f[i][j] = max(f[i - 1][j], f[i][j - w[i]] + v[i])
        理由是当我们这样转移时，f[i][j - w[i]] 已经由 f[i][j - 2 * w[i]] 更新过，
        那么 f_{i,j-w_i} 就是充分考虑了第 i 件物品所选次数后得到的最优结果。
        换言之，我们通过局部最优子结构的性质重复使用了之前的枚举过程，优化了枚举的复杂度。
*/

/*
与 0-1 背包相同，我们可以将第一维去掉来优化空间复杂度。如果理解了 0-1 背包的优化方式，就不难明白压缩后的循环是正向的（也就是上文中提到的错误优化）。
*/
#define IOS std::ios::sync_with_stdio(false), std::cin.tie(0), std::cout.tie(0);
#include<bits/stdc++.h>
using ll = long long;
using ldou = long double;
using unll = unsigned long long;
using namespace std;

const int N = 1e5 + 5;
const ll INF = 3e16;
const int MODE = 998244353;
unll n, m, k;
ll v[N],  w[N];

void test01() { // 初始代码
    ll f[N][N];
    for (int i = 1; i <= n; i++)
		for (int j = w[i]; j <= m; j++)
			for (int k = 0; k * w[i] <= j; k++)
				f[i][j] = max(f[i][j], f[i - 1][j - k * w[i]] + k * v[i]);
}

void test02() {//优化
    ll f[N];
    for (int i = 1; i <= n; i++)
        for (int j = w[i]; j <= m; j++)
            f[j] = max(f[j], f[j - w[i]] + v[i]);
}

void solve() {

	cin >> m >> n;

    for (int i = 1; i <= n; i++) cin >> w[i] >> v[i];

    
}

signed main() {
	IOS;
	//inout;
	int TTT = 1; //cin >> TTT;
	while (TTT--)
		solve();
	return 0;
}