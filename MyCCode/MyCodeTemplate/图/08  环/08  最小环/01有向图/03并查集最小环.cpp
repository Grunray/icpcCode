
//  o(n)

#define _CRT_SECURE_NO_WARNINGS
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

unll n, m, k;

const int N = 2e5 + 5;
int f[N], d[N], minn, last;   //f保存祖先节点，d保存到其祖先节点的路径长。

int fa(int x) {
	if (f[x] != x) {                      //查找时沿途更新祖先节点和路径长。
		int last = f[x];                 //记录父节点（会在递归中被更新）。
		f[x] = fa(f[x]);                 //更新祖先节点。 
		d[x] += d[last];                 //更新路径长（原来连在父节点上）。
	}
	return f[x];
}
void check(int a, int b) {
	int x = fa(a), y = fa(b);               //查找祖先节点。 
	if (x != y) { 
		f[x] = y;
		d[a] = d[b] + 1; 
	}   //若不相连，则连接两点，更新父节点和路径长。 
	else 
		minn = min(minn, d[a] + d[b] + 1);   //若已连接，则更新最小环长度。 
	return;
}

void solve() {

	cin >> n;
	frp f[i] = i;         //祖先节点初始化为自己，路径长为0。 
	minn = 0x7777777;
	int t;
	frp {
		cin >> t;
		check(i, t);                    //检查当前两点是否已有边相连接。 
	}
	cout << minn;
}

signed main() {
	//std::ios::sync_with_stdio(false), std::cin.tie(0), std::cout.tie(0);
	//freopen("wrt.txt", "r", stdin); //freopen("out.txt", "w", stdout);
	int TTT = 1; //cin >> TTT;
	while (TTT--) {
		solve();
	}
		
	return 0;
}
