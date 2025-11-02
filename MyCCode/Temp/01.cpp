

#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
#include<unordered_set>
#include<unordered_map>
using namespace std;

// #define int long long

#define bit(x) (1LL << (res))
#define lowbit(x) (res & -res)
#define sq(x) ((res) * (res))
#define all(x) x.begin(), x.end()

#define rep(a, b, c, d) for (int a = (b); a <= (c); a += (d))
#define fep(a, b, c, d) for (int a = (b); a >= (c); a -= (d))

#define look_time cout << (clock() - Time) * 1.0 / CLOCKS_PER_SEC << '\n'
#define look_memory cout << abs(&M2 - &M1) / 1024.0 / 1024 << " MB\n"

using unll = unsigned long long;
using ll = long long;

using PII = pair<int, int>;


/*--int128--*/
//inline __int128 read() {//__int128模板 
//	__int128 x = 0, f = 1;
//	char ch = getchar();
//	while (ch < '0' || ch > '9') { if (ch == '-')  f = -1; ch = getchar(); }
//	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
//	return x * f;
//}
//inline void print(__int128 x) {
//	if (x < 0) { putchar('-'); x = -x; }
//	if (x > 9)  print(x / 10);
//	putchar(x % 10 + '0');
//}
/*--fast read--*/
template<typename T> T read() {
	T X = 0; bool flag = true; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') flag = false; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { X = (X << 1) + (X << 3) + ch - '0'; ch = getchar(); }
	if (flag) return X;
	return ~(X - 1);
}
template<typename T> void write(T X) {
	if (X < 0) { putchar('-'); X = ~(X - 1); }
	int s[100], top = 0;
	while (X) { s[++top] = X % 10; X /= 10; }
	if (!top) s[++top] = 0;
	while (top) putchar(s[top--] + '0');
}
inline string read() {
	string str = ""; char ch = getchar();
	//处理空格、换行或回车 
	while (ch == ' ' || ch == '\n' || ch == '\r') ch = getchar();
	//读入
	while (ch != ' ' && ch != '\n' && ch != '\r') { str += ch; ch = getchar(); }
	return str;
}
/*--const--*/
const int INF = 0x3f3f3f3f;
const long long LINF = 0x3f3f3f3f3f3f3f3f;
const long long MODE = 998244353;
const long long MOD = 1e6 + 7;

const int dx[] = { 1, 0,-1, 0,   1, 1,-1,-1 };
const int dy[] = { 0,-1, 0, 1,  -1, 1,-1, 1 };

const double eps = 1e-8;
double Pi = acos(-1.0);
/*--math--*/
long long qpow(long long x, long long y) {
	x %= MODE;
	long long res = 1;
	while (y) {
		if (y & 1) res = res * x % MODE;
		x = x * x % MODE;
		y >>= 1;
	}
	return res;
}
long long gcd(long long a, long long b) { // 最大公约数
	while (b ^= a ^= b ^= a %= b)
		;
	return a;
}
long long lcm(long long a, long long b) { // 最小公倍数
	return a / gcd(a, b) * b;
}

/*------------CODE------------*/
// r行 c列

const long long N = 1e6 + 50;
const long long M = 1e6 + 50;

// int months[15] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
//priority_queue<ll> pq;//这是一个大根堆q
//priority_queue<int, vector<int>, greater<int> >q;//这是一个小根堆q
//priority_queue<int, vector<int>, greater<int> >pq; // 小根
//priority_queue<pair<int,int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
//vector<vector<int> > vv(5000 + 10, vector<int>(5000 + 10, 0));

class Solution {
public:
    int compareVersion(string version1, string version2) {
        
    }
};

void solve() {

	int n, m; cin >> n >> m;

	
	





	


}


void pretreatment()
{
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	//int Time = clock();
	//look_memory;
	//freopen("wrt.in", "r", stdin);
	//freopen("out.out", "w", stdout);

	signed T = 1;
	//scanf("%d", &T);
	cin >> T;
	// pretreatment();
	while (T--) {
		solve();
	}
	//look_time;
	return 0;
}
