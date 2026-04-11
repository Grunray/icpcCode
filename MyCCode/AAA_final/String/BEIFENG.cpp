#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;

//#define int long long

#define bit(x) (1LL << (x))
#define lowbit(x) (x & -x)
#define sq(x) ((x) * (x))

#define rep(a, b, c, d) for (int a = (b); a <= (c); a += (d))
#define fep(a, b, c, d) for (int a = (b); a >= (c); a -= (d))

using unll = unsigned long long;
using ll = long long;

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
/*--const--*/
const int INF = 0x3f3f3f3f;
const long long LINF = 0x3f3f3f3f3f3f3f3f;
const long long MODE = 998244353;
const long long MOD = 1e9 + 7;

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

// int months[15] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };

//priority_queue<ll> pq;//这是一个大根堆q
//priority_queue<int, vector<int>, greater<int> >q;//这是一个小根堆q
//priority_queue<ll, vector<ll>, greater<ll> >pq; // 小根

const long long N = 1e6 + 50;
const long long M = 1e6 + 50;

ll n, m;

class Tree { // 求解任意子区间的最大字段和
public:
	struct Status {
		int lSum, rSum, mSum, iSum;
	};
	Status pushUp(Status l, Status r) {
		int iSum = l.iSum + r.iSum;
		int lSum = max(l.lSum, l.iSum + r.lSum);
		int rSum = max(r.rSum, r.iSum + l.rSum);
		int mSum = max(max(l.mSum, r.mSum), l.rSum + r.lSum);
		return (Status) {lSum, rSum, mSum, iSum};
	};
	Status get(vector<int> &a, int l, int r) {
		if (l == r) return (Status) {a[l], a[l], a[l], a[l]};
		int m = (l + r) >> 1;
		Status lSub = get(a, l, m);
		Status rSub = get(a, m + 1, r);
		return pushUp(lSub, rSub);
	}
	int maxSubArray(vector<int>& nums, int l, int r) { // [l, r)
		return get(nums, l, r - 1).mSum;
	}
};

struct STRING
{
	struct IDEA
	{
		/* 
			*字典序 -> 字典树
					-01特定的字典顺序找最小字典序的串：trie+拓扑
		*/
	};
	
	struct FunctionsOfC_Plusplus
	{	
		string str;
		string sub;
		int x;
		double pi;
		void func() 
		{ 
			// 转换大小写
			transform(str.begin(), str.end(), sub.begin(), ::tolower/*这里可以是自定义函数*/);
			//*-----------------------------------*//
			// 转换为字符串
			str = to_string(x);
			sub = to_string(pi);
			//*-----------------------------------*//
			// 进制转化， 10->R
			// 只能用字符数组 某些地方可能用不了
			int R = 2;
			char ch[N];
			_itoa(x, ch, R); 
			// 所以
			string itoa(int x);
			//*-----------------------------------*//
			// 求str的下一个字典序，直接修改str
			// str是最大的字典序时，返回0
			next_permutation(str.begin(), str.end());
		}
		string itoa(int x) { // 10->2
			string res;
			while(x) {
				if(x & 1) res += '1';
				else res += '0';
				x >>= 1;
			}
			reverse(res.begin(), res.end());
			return res;
		}
	};
	
	// 哈希
	struct HASHE { // 下标从1开始
		const int Pri = 13331;
		unll p[N], h[N];
		unll val = 0;
		// 求一个串的哈希值相当于求前缀和
		unll init(string str) {
			p[0] = 1; h[0] = 0;
			int len = str.length();
			for (int i = 1; i < len; i++) {
				p[i] = p[i - 1] * Pri;
				h[i] = h[i - 1] * Pri + str[i];
			}
			val = h[len - 1];
			return val; // 当前串的哈希值
		}
		// 求子串的哈希值相当于求区间和
		unll getSubHash(int l, int r) { return h[r] - h[l - 1] * p[r - l + 1]; }
		bool isSameSub(int l1, int r1, int l2, int r2) { return getSubHash(l1, r1) == getSubHash(l2, r2); }
	};
	struct Binary_HASHE
	{
		unll lh[N], rh[N], p[N];
		const ll Pri = 131ll;
		char s[N], c[N];
		unll pos;
		//ll len;
		ll lhget(ll l, ll r) {
			return ((lh[r] - lh[l - 1] * p[r - l + 1] % MODE + MODE) % MODE + MODE) % MODE;
		}
		ll rhget(ll l, ll r) {
			return ((rh[l] - rh[r + 1] * p[r - l + 1] % MODE + MODE) % MODE + MODE) % MODE;
		}
		ll cal(ll x, ll d) {
			if (x >= d)
				return rhget(pos + x - d, pos + x - 1);
			else {
				ll res1 = rhget(pos, pos + x - 1);
				ll res2 = lhget(pos + x, pos + d - 1);
				return (res1 * p[d - x] % MODE + res2) % MODE;
			}
		}
		char Getchar(ll x, ll d) {
			if (x >= d) return s[pos + x - d];
			else return s[pos + d - 1];
		}
		bool check(ll x, ll y) {
			ll l = 0, r = n - pos;
			while (l < r) {
				ll mid = (l + r + 1) / 2;
				ll p = cal(x, mid);
				ll q = cal(y, mid);
				if (p == q) l = mid;
				else r = mid - 1;
			}
			l++;
			char _x = Getchar(x, l);
			char _y = Getchar(y, l);
			return  _x > _y;
		}
	};
	// 字典树
	struct Trie {
		static const int N = (1e5 + 50);
		static const int ALPHA = 65;
		int nex[N][ALPHA], cnt;
		int exist[N]; 
		int done[N];
		bool vis[N];
		void init() {
			for (int i = 0; i <= cnt; i++) for (int j = 0; j < ALPHA; j++) nex[i][j] = 0;
			for (int i = 0; i <= cnt; i++) exist[i] = 0;
			cnt = 0;
		}
		int getAscii(char ch) { //  A-Z a-z 0-9
			int ascii = 0;
			if (isupper(ch))      ascii = int(ch - 'A');
			else if (islower(ch)) ascii = int(ch - 'a' + 26);
			else if (isdigit(ch)) ascii = int(ch - '0' + 52);
			return ascii;
		}
		void insert(string s) {  // 插入[词]
			int p = 0, len = s.length();
			for (int i = 0; i < len; i++) {
				int c = getAscii(s[i]);
				if (!nex[p][c]) nex[p][c] = ++cnt;  // 如果没有，就添加结点
				p = nex[p][c];
				++exist[p];
			}
			done[p]++; // 记录成为一个[词]
		}
		int find(string s) {  // 查找[词]
			int p = 0, len = s.length();
			for (int i = 0; i < len; i++) {
				int c = getAscii(s[i]);
				if (!nex[p][c]) return 0;
				p = nex[p][c];
			}
			if (done[p]) return exist[p]; // 有这个[词]
			return 0; // 没有这个[词]
		}
		// 查找一条链上有多少个词，即查找词链，eg: i -> int -> intern -> internet 返回4
			// 本质上还是类似于find()函数查找[词]，因为这些词都是已有的，所以到internet(词链最长的单词)时，可以计数完整的词链
		int findWordChains(string s) {
			int p = 0, len = s.length();
			int ans = 0;
			for (int i = 0; i < len; i++) {
				int c = getAscii(s[i]);
				if (!nex[p][c]) return 0;
				p = nex[p][c];
				if (done[p])ans++;
			}
			if (done[p]) return ans;
			return 0;
		}
		// 查找树中与s拥有相同的前缀的[词]的数量luoguP2922
		// insert()函数那，必须是done[p]++，因为插入到树的串会重复
		int cntMaxPrefix(string s) {
			int p = 0, len = s.length();
			int res = 0;
			for (int i = 0; i < len; i++) {
				int c = getAscii(s[i]);
				if (!nex[p][c]) return res;
				p = nex[p][c];
				res += done[p];
			}
			return res + exist[p] - done[p];
		}
		// 树中的最长公共前缀
		int longestCommonPrefix(string s) {
			int p = 0, len = s.length();
			int lenOfPrefix = 0;
			for (int i = 0; i < len; i++) {
				int c = getAscii(s[i]);
				if (!nex[p][c]) return lenOfPrefix;
				p = nex[p][c];
				lenOfPrefix++;
			}
			return lenOfPrefix;
		}
		int findUnique(string s) { // 查找[词]，并且判断该[词]是否访问过
			int p = 0, len = s.length();
			for (int i = 0; i < len; i++) {
				int c = getAscii(s[i]);
				if (!nex[p][c]) return 0;
				p = nex[p][c];
			}
			if (done[p]) { // 有这个[词]
				if (vis[p]) return -1; // 重复访问
				vis[p] = true;
				return exist[p];
			}
			return 0;
		}
		int findStrToMinDicorder(string s) {  // 自定义字典序(未知)下，查找s在树上是否为字典序最小的串
			int p = 0, len = s.length();
			bool adj[ALPHA][ALPHA];
			memset(adj, false, sizeof adj);
			vector<int> in(ALPHA);
			for (int i = 0; i < len; i++) {
				int c = getAscii(s[i]);
				if (done[p]) return 0; // 如果有前缀
				for(int j = 0; j < ALPHA; j++) {
					if(c != j && nex[p][j] && !adj[c][j]) { // 不是自己，有子节点，无这条topo边
						in[j]++;
						adj[c][j] = 1;
					}
				}
				p = nex[p][c];
			}
			//topo-start
			int ans = 0;
			queue<int> q;
			for(int i = 0; i < ALPHA; i++)
				if(!in[i]) q.push(i);
			while(!q.empty()) {
				int u = q.front(); q.pop();
				ans++;
				for(int i = 0; i < ALPHA; i++) {
					if(adj[u][i])
						if(!--in[i]) q.push(i);
				}
			}
			//topo-end
			if(ans != ALPHA) return 0;
			else return ans;
		}
	};
	// 维护异或的字典树
	//给定一棵n点的带权树，结点下标1-n。寻找树中找两个结点，求最长的异或路径。
	//异或路径指的是指两个结点之间唯一路径上的所有边权的异或。
	struct xorTrie {
		vector<pair<int, long long> >adj[N];
		int cnt = 0, tot = 1, res = 0;
		int dis[N], ch[N << 5/*N * 32*/][2];

		void insert(int x) {
			for (int i = 30, u = 1; i >= 0; --i) {
				int c = ((x >> i) & 1);  // 二进制一位一位向下取
				if (!ch[u][c]) ch[u][c] = ++tot;
				u = ch[u][c];
			}
		}
		int get(int x) {
			int ans = 0;
			for (int i = 30, u = 1; i >= 0; --i) {
				int c = ((x >> i) & 1);
				if (ch[u][c ^ 1]) {  // 如果能向和当前位不同的子树走，就向那边走
					u = ch[u][c ^ 1];
					ans |= (1 << i);
				}
				else u = ch[u][c];
			}
			return res = max(res, ans);  // 更新答案
		}
		void add(int u, int v, int w) { adj[u].push_back({ v, w }); }
		void dfs(int u, int fa) {
			insert(dis[u]);
			get(dis[u]);
			for (auto it : adj[u]) {  // 遍历子节点
				int v = it.first;
				long long w = it.second;
				if (v == fa) continue;
				dis[v] = dis[u] ^ w;
				dfs(v, u);
			}
		}
	};
	// 前缀和KMP
	struct PrefixAndKMP
	{
		// 前缀函数
		// 查找:字符串s, i from 0 to sub.size()-1 形成的子串 是否 有相等的真前缀和真后缀
		// 有的话，长度是pi[i]
		//01找最短的「压缩」表示，也即我们希望寻找一个最短的字符串 t，使得 s 可以被 t 的一份或多份拷贝的拼接表示
			//计算 s 的前缀函数。通过使用该函数的最后一个值 pi[n - 1]，我们定义值 k = n - pi[n - 1]。
			//我们将证明，如果 k 整除 n，那么 k 就是答案，否则不存在一个有效的压缩，故答案为 n。
		vector<int> prefix_function(string s) { // 返回的pi数组中，前缀和后缀会有重叠, eg: aaaa, 会有aaa的前缀和aaa的后缀，下面会给一个没有重叠的pi数组的算法
			int len = (int)s.length();
			vector<int> pi(len); // 前缀
			for (int i = 1; i < len; i++) {
				int j = pi[i - 1];
				while (j > 0 && s[i] != s[j]) j = pi[j - 1];
				if (s[i] == s[j]) j++;
				pi[i] = j;
			}
			return pi;
		}
		vector<int> prefix_function_WithoutOverlap(string s) { // 排除有重叠的前缀和后缀的 前缀函数算法
			int len = (int)s.length();
			vector<int> pi(len); // 前缀
			vector<int> num(len + 2);
			num[0] = 0; num[1] = 1;
			vector<int>res;
			for (int i = 1; i < len; i++) {
				int j = pi[i - 1];
				while (j > 0 && s[i] != s[j]) j = pi[j - 1];
				if (s[i] == s[j]) j++;
				pi[i] = j;
				num[i + 1] = num[j] + 1;
			}
			for (int i = 1, j = 0; i < len; i++) {
				while (j > 0 && s[i] != s[j]) j = pi[j - 1];
				if (s[i] == s[j]) j++;
				while ((j << 1) > i + 1) j = pi[j - 1];
				res.push_back(num[j]);
			}
			return res; // 返回的就是去除重叠部分的前缀数组
		}
		//求最短相同前后缀长度||求最长循环节长度||所有前缀的最大周期长度
		vector<int> prefix_function_MinSamePreSuf_OR_MaxLoopSection(string s) {
			int len = (int)s.length();
			vector<int> pi(len + 2); // 前缀
			vector<int> pii(len + 2);
			vector<int> res(len + 2);
			for (int i = 1; i < len; i++) {
				int j = pi[i - 1];
				while (j > 0 && s[i] != s[j]) j = pi[j - 1];
				if (s[i] == s[j]) j++;
				pi[i] = j;
			}
			// 写法 1
			for (int i = 0; i < len; i++) pii[i + 1] = pi[i];
			int now = 0;
			for (int i = 1; i <= len; i++) {
				now = i;
				while (pii[now]) now = pii[now];
				if (pii[i]) pii[i] = now;
				res.push_back(i - now);
			}
			// 写法 2
			//for (int i = 1, j = 0; i < len; i++) {
			//	while (j > 0 && s[i] != s[j]) j = pi[j - 1];
			//	if (s[i] == s[j]) j++;
			//	pi[i] = j;
			//}
			//for (int i = 0; i < len; i++) {
			//	int j = pi[i];
			//	while (j > 0 && pi[j - 1]) j = pi[j - 1]; // 找最小的循环节长度
			//	pi[i] = j;
			//	if (pi[i])
			//		res.push_back(i + 1 - pi[i]);
			//}
			return res;
		}
		int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) { // 最长公共前缀的长度
			set<int> st1, st2;
			for(int i = 0; i < arr1.size(); i++) {
				int now = arr1[i];
				while(now) {
					st1.insert(now);
					now /= 10;
				}
			}
			for(int i = 0; i < arr2.size(); i++) {
				int now = arr2[i];
				while(now) {
					st2.insert(now);
					now /= 10;
				}
			}
			// 求交集的数最大长度
			set<int> itsec;
			set_intersection(st1.begin(), st1.end(), st2.begin(), st2.end(), inserter(itsec, itsec.begin()));
			int len = 0;
			if(!itsec.empty()) {
				int res = *(itsec.rbegin());
				while(res) {
			  		len++;
					res /= 10;
				}
				return len;
			}
			else return len;
		}
		string compressString(string s[], int n/*词的个数*/) { // 前串的后缀 是 后串的前缀 ， 求前后缀合体后的最终串，eg: 1101 1001 001001 101 010 -> 1101001001010 ||  want to order -> wantorder
			string res = s[1];
			rep(i, 2, n, 1) {
				int len = min(res.length(), s[i].length());
				// 中间的杂串是随便加的，目的是隔开原本的两串
				string temp = s[i] + "!@#$%^&*()njm[];'./~~~123112asfdnaowdhj" + res.substr(res.size() - len, len);
				vector<int>pi = prefix_function(temp);
				for (int j = pi[pi.size() - 1]; j < s[i].length(); j++) res += s[i][j];
			}
			//优化空间的写法：
			/*cin >> res;
			rep(i, 2, n, 1) {
				string str; cin >> str;
				int len = min(res.length(), str.length());
				temp = str + "!@#$%^&*()njm[];'./~~~123112asfdnaowdhj" + res.substr(res.size() - len, len);
				vector<int>pi = pakmp.prefix_function(temp);
				for (int j = pi[pi.size() - 1]; j < str.length(); j++) res += str[j];
			}*/
			return res;
		}
		string getShortestPalindrome(string s) { // 求后缀回文 || 找前缀是S的最短回文串
			string rev(s);
			reverse(rev.begin(), rev.end());
			vector<int> next(s.size());
			next[0] = -1, next[1] = 0;
			int i = 2, cn = 0;
			while (i < next.size()) {
				if (s[i - 1] == s[cn]) {
					next[i] = cn + 1;
					i++, cn = cn + 1;
				} else if (cn != 0) {
					cn = next[cn];
				} else {
					next[i] = 0;
					i++;
				}
			}
			int x = 0, y = 0;
			while (x < rev.size()) {
				if (rev[x] == s[y]) {
					x++, y++;
				} else if (y != 0) {
					y = next[y];
				} else {
					x++;
				}
			}
			string str1 = s.substr(y);
			reverse(str1.begin(), str1.end());
			s = str1 + s;
			return s;
		}
		int getMinPeriod(string s) { // s的最小周期  如果求最大周期长度，就是 maxLen = pi[len - 1]
			vector<int>pi = prefix_function(s);
			int len = s.length();
			if (!(len % (len - pi[len - 1]))) return len - pi[len - 1];
			else return len;
		}
		// KMP
			// 在字符串中查找子串的位置
		vector<int> KMP(string text, string pattern) {
			string cur = pattern + '#' + text; // cur = sub + str
			int sz1 = text.size(), sz2 = pattern.size();
			vector<int> kmp;
			vector<int> pi = prefix_function(cur);
			for (int i = sz2 + 1; i <= sz1 + sz2; i++) {
				if (pi[i] == sz2) kmp.push_back(i - 2 * sz2);
			}
			return kmp;
		}
		// exKMP  z函数
		vector<int> z_function(string s) {
			int n = (int)s.length();
			vector<int> z(n);
			for (int i = 1, l = 0, r = 0; i < n; ++i) {
				if (i <= r && z[i - l] < r - i + 1) {
					z[i] = z[i - l];
				}
				else {
					z[i] = max(0, r - i + 1); // 跳转
					while (i + z[i] < n && s[z[i]] == s[i + z[i]]) ++z[i];
				}
				if (i + z[i] - 1 > r) l = i, r = i + z[i] - 1;
			}
			return z;
		}
		// 统计每个前缀出现的次数
		vector<int> count_occurrences(vector<int> pi, int len) {
			vector<int> ans(len + 1);
			for (int i = 0; i < len; i++)
				ans[pi[i]]++;
			for (int i = len - 1; i > 0; i--)
				ans[pi[i - 1]] += ans[i];
			for (int i = 0; i <= len; i++)
				ans[i]++;
			return ans;
		}  
	};
	struct Manacher
	{
		pair<vector<int>, vector<int> > MANACHER(string s) { // 算法本体
			int len = s.length();
			//string str; // 好像？不用改串？？？-> 哦~，懂了，如过只用一个数组来存回文长度的话就合并， 然后用d1的算法即可 // 如MANACHER2
			//for (int i = 0; i < len; i++) { // eg原串aaa -> #a#a#a
			//	str.push_back('#');
			//	str.push_back(s[i]);
			//}
			//str = "%" + str + "#@"; // 最终变为 %#a#a#a#@
			//len = s.length(); // 更新长度
			// 具体算法
			vector<int> d1(len);
			for (int i = 0, l = 0, r = -1; i < len; i++) {
				int k = (i > r) ? 1 : min(d1[l + r - i], r - i + 1);
				while (0 <= i - k && i + k < len && s[i - k] == s[i + k])
					k++;
				d1[i] = k--;
				if (i + k > r) {
					l = i - k;
					r = i + k;
				}
			}
			vector<int> d2(len);
			for (int i = 0, l = 0, r = -1; i < len; i++) {
				int k = (i > r) ? 0 : min(d2[l + r - i + 1], r - i + 1);
				while (0 <= i - k - 1 && i + k < len && s[i - k - 1] == s[i + k])
					k++;
				d2[i] = k--;
				if (i + k > r) {
					l = i - k - 1;
					r = i + k;
				}
			}
			return { d1, d2 };
		}
		vector<int> MANACHER2(string s) { // 算法本体
			int len = s.length();
			string str; // 好像？不用改串？？？-> 哦~，懂了，如过只用一个数组来存回文长度的话就合并，然后用d1的算法即可
			for (int i = 0; i < len; i++) { // eg原串aaa -> #a#a#a
				str.push_back('#');
				str.push_back(s[i]);
			}
			str = "%" + str + "#@"; // 最终变为 %#a#a#a#@
			len = str.length(); // 更新长度
			// 具体算法 形如原算法的d1，一致
			vector<int> d(len);
			for (int i = 0, l = 0, r = -1; i < len; i++) {
				int k = (i > r) ? 1 : min(d[l + r - i], r - i + 1);
				while (0 <= i - k && i + k < len && str[i - k] == str[i + k])
					k++;
				d[i] = k--;
				if (i + k > r) {
					l = i - k;
					r = i + k;
				}
			}
			return d;//求最长回文长度就是数组中最大的元素 - 1
		}
		pair<int, int> getMaxOrMinLenOfPalindromeSubstring(string s, bool MaxOrMin) { // 奇 偶 %% true->Max  false->Min
			pair<vector<int>, vector<int> >pv = MANACHER(s);
			vector<int>d1 = pv.first;
			vector<int>d2 = pv.second;
			int Odd = 0, Even = 0;
			if (MaxOrMin) {
				for (auto x : d1) Odd = max(Odd, x);
				for (auto x : d2) Even = max(Even, x);
			}
			else {
				for (auto x : d1) if (x) Odd = min(Odd, x);
				for (auto x : d2) if (x) Even = min(Even, x);
			}
			Odd = Odd * 2 - 1;
			Even = Even * 2;
			return { Odd ,Even };
		}
		string longestPalindrome(string s) { // 最长的回文子串的串
			pair<vector<int>, vector<int> > mana = MANACHER(s);
			int pos1 = 0, pos2 = 0;
			int maxn1 = 0, maxn2 = 0;
			for(int i = 0; i < mana.first.size(); i++) {
				if (maxn1 < mana.first[i] * 2 - 1) {
					maxn1 = mana.first[i] * 2 - 1;
					pos1 = i;
				}
				// cout << mana.first[i] << ' ';
			}
			// cout << '\n';
			for(int i = 0; i < mana.second.size(); i++) {
				if (maxn2 < mana.second[i] * 2) {
					maxn2 = mana.second[i] * 2;
					pos2 = i;
				}
				// cout << mana.second[i] << ' ';
			}
			// cout << '\n';
			// cout << pos1 << ' ' << maxn1 << '\n';
			// cout << pos2 << ' ' << maxn2 << '\n';
			// cout << '\n';
			string res;
			if(maxn1 >= maxn2) {
				for(int i = pos1 - maxn1 / 2; i < pos1 + (maxn1 + 1) / 2; i++) {
					res += s[i];
				}
				// cout << 1 << "  " << pos1 - maxn1 / 2 << "  " << pos1 + (maxn1 + 1) / 2 << '\n';
			}
			else {
				for(int i = pos2 - maxn2 / 2; i < pos2 + maxn2 / 2; i++) {
					res += s[i];
				}
				// cout << 2 << "  " << pos2 - maxn2 / 2 << "  " << pos2 + (maxn2) / 2 << '\n';
			}
			return res;
		}
		int getMinLenToAddChTOPalindrome(string s) { // 在一个串右边的最少添加多少个字符以使得新串回文
			pair<vector<int>, vector<int> >pv = MANACHER(s);
			vector<int>d1 = pv.first;
			vector<int>d2 = pv.second;
			int Odd = 0, Even = 0;
			for (int i = 0; i < d1.size(); i++)
				if (d1[i] + i == s.length()) // 当前串回文的长度加上本来的长度 == 原长
					Odd = max(Odd, d1[i]);
			for (int i = 0; i < d2.size(); i++)
				if (d2[i] + i == s.length())
					Even = max(Even, d2[i]);
			Odd = Odd * 2 - 1;
			Even = Even * 2;
			return s.length() - max(Odd, Even); // 如果求的是最大后缀回文的话，返回max(Odd, Even)即可
		}
	};
	// 最小表示法
	ll minn_show(vector<ll> sec) {
		ll k = 0, i = 1, j = 2;
		// 破环成链
		rep(i, 0, n - 1, 1) sec[n + i] = sec[i];
		while (k < n && i < n && j < n) {
			for (k = 0; k < n && sec[(i + k) % n] == sec[(j + k) % n]; k++)
				;
			sec[(i + k) % n] > sec[(j + k) % n] ? i = i + k + 1 : j = j + k + 1;
			if (i == j) i++;
		}
		return min(i, j);
	}
	// AC自动机
	struct AC {
		int tr[N][26], tot;
		int e[N], fail[N];
		void insert(string s) {
			int u = 0;
			for (int i = 0; i < s.length(); i++) {
				if (!tr[u][s[i] - 'a']) tr[u][s[i] - 'a'] = ++tot;  // 如果没有则插入新节点
				u = tr[u][s[i] - 'a'];                              // 搜索下一个节点
			}
			e[u]++;  // 尾为节点 u 的串的个数
		}
		void build() {
			queue<int> q;
			for (int i = 0; i < 26; i++)
				if (tr[0][i]) q.push(tr[0][i]);
			while (q.size()) {
				int u = q.front();
				q.pop();
				for (int i = 0; i < 26; i++) {
					if (tr[u][i]) {
						fail[tr[u][i]] =
							tr[fail[u]][i];  // fail数组：同一字符可以匹配的其他位置
						q.push(tr[u][i]);
					}
					else tr[u][i] = tr[fail[u]][i];
				}
			}
		}
		int query(string s) {
			int u = 0, res = 0;
			for (int i = 0; i < s.length(); i++) {
				u = tr[u][s[i] - 'a'];  // 转移
				for (int j = u; j && e[j] != -1; j = fail[j])
					res += e[j], e[j] = -1;
			}
			return res;
		}
	};
	// 后缀自动机
	struct SAM {
		// 每次End 是代表新产生的位置的作用点
	// 新创建的数组要清空
		//const int Max = ((1e5 + 5) * 2); // M节点数量,字符串长度的两倍
		int ch[M][30], mxlen[M], par[M], tp[M];
		int End, tot;
		int siz[M];
		int newnod() {
			tot++;
			mxlen[tot] = par[tot] = 0;
			memset(ch[tot], 0, sizeof(ch[tot]));
			siz[tot] = 0;
			return tot;
		}
		void clear() { // 1为root
			tot = 0;
			End = newnod();
		}
		void extend(int c) {
			int p = End; End = newnod();
			mxlen[End] = mxlen[p] + 1;
			siz[End] = 1;
			for (; p && !ch[p][c]; p = par[p]) ch[p][c] = End;
			if (!p) par[End] = 1;
			else {
				int q = ch[p][c];
				if (mxlen[p] + 1 == mxlen[q]) par[End] = q;
				else {
					int nq = newnod(); mxlen[nq] = mxlen[p] + 1; // nq是新产生的分叉点
					memcpy(ch[nq], ch[q], sizeof(ch[q]));
					par[nq] = par[q], par[End] = par[q] = nq;
					for (; ch[p][c] == q; p = par[p]) ch[p][c] = nq;
				}
			}
		}
		void build() {//倒叙循环满足拓扑
			static int cnt[M];
			rep(i, 0, tot + 1, 1) cnt[i] = 0;
			rep(i, 1, tot + 1, 1) cnt[mxlen[i]]++;
			rep(i, 1, tot + 1, 1) cnt[i] += cnt[i - 1];
			fep(i, tot, 1, 1) tp[cnt[mxlen[i]]--] = i;
		}

	};
	// 回文树查询回文子串出现次数
	struct PAM {
		const int INF = 0x3f3f3f3f;
		int sz, tot, last;
		int cnt[N], ch[N][26], len[N], fail[N];
		//int anc[N]/*这组等差数列的端点*/, dif[N]/*前向差分*/;
        vector<int> anc, dif;
		char s[N];

		int node(int l) {  // 建立一个新节点，长度为 l
			sz++;
			memset(ch[sz], 0, sizeof(ch[sz]));
			len[sz] = l;
			//fail[sz] = cnt[sz] = 0;
			return sz;
		}
		void clear() {  // 初始化
			sz = -1;
			last = 0;
			s[tot = 0] = '$';
			node(0); node(-1);
			fail[0] = 1;
		}
		int getfail(int x) {  // 找后缀回文
			while (s[tot - len[x] - 1] != s[tot]) x = fail[x];
			return x;
		}
		void insert(char c, int i) {  // 建树
			s[++tot] = c;
			int now = getfail(last);
			if (!ch[now][c - 'a']) {
				int x = node(len[now] + 2);
				fail[x] = ch[getfail(fail[now])][c - 'a'];
				ch[now][c - 'a'] = x;
			}
			last = ch[now][c - 'a'];
			//if (i > n)// 若破链成环
			cnt[last]++;
		}
		long long CountSubPalindrome() { // 回文树查询回文子串出现次数
			long long ans = 0;
			for (int i = sz; i >= 0; i--) {
				cnt[fail[i]] += cnt[i];
			}
			for (int i = 2; i <= sz; i++) {  // 更新答案
				//if (len[i] > n) continue;// 若破链成环
				ans = (ans + (((1ll) * len[i] * cnt[i]) % MODE) * cnt[i]) % MODE;

			}
			return ans;
		}
		// 以下部分是用于最小回文分割
			// 即 ： 给你一个字符串 s，请你将 s 分割成一些子串，使每个子串都是回文串
        void init(int len_s) {
			fail[0] = fail[1] = tot = last = 1; 
			len[1] = -1;
            anc.resize(len_s + 5);
            dif.resize(len_s + 5);
		}
        int getfail2(int x, int i) {
			while (s[i - len[x] - 1] != s[i]) x = fail[x];
			return x;
		}
        void insert2(char c, int i) {
			//s[++tot] = c;
			int now = getfail2(last, i);
			if (!ch[now][c - 'a']) {
				// int x = node(len[now] + 2);
				int x = ++tot;
				len[x] = len[now] + 2;
				int p = getfail2(fail[now], i);
				fail[x] = p = ch[p][c - 'a'];
				ch[now][c - 'a'] = last = x;
				dif[x] = p ? len[x] - len[p] : INF;
				anc[x] = (dif[x] == dif[p]) ? anc[p] : p;
			}
			//cout << c << ' ' << i << '\n';
			else last = ch[now][c - 'a'];
			cnt[last]++;
		}
		int cmin(int& x, int y) { return y < x ? x = y : 0; }
		int minCutSubPalindrome() { // 下标从1开始
			//int len_s = s.length();
			int len_s = strlen(s + 1);
			vector<int> dp(len_s + 10, INF); dp[0] = 0;
			vector<int> g(len_s + 10, INF);
			init(len_s);
			for(int i = 1; i <= len_s; i++) {
				insert2(s[i], i);
				cmin(dp[i], dp[i - len[last]] + 1);
				for(int j = last; fail[j]; j = anc[j]) {
					int pos = i - len[j] + 1;
					if(anc[j] == fail[j]) 
						g[pos] = INF;
					//cout << j << '\n';
					cmin(g[pos], dp[i - len[anc[j]]] + 1);
					cmin(dp[i], g[pos]);
				}
			}
			return dp[len_s] - 1;
		}
	};
	//Lyndon 分解
	struct Lyndon
	{
		//s 的字典序严格小于 s 的所有后缀的字典序，我们称 s 是 Lyndon 串。
		//例，a,b,ab,aab,abb,ababb,abcd 都是 Lyndon 串
		vector<int> duval_getRightPoint(string const& s) { // 下标从 1 开始
			int len = s.size(), i = 1;
			vector<string> lyndon;
			vector<int> right_point;
			while (i < len) {
				int j = i + 1, k = i;
				while (j < len && s[k] <= s[j]) {
					if (s[k] < s[j]) k = i;
					else k++;
					j++;
				}
				while (i <= k) {
					lyndon.push_back(s.substr(i, j - k)); // Lyndon串
					i += j - k;
					right_point.push_back(i);
				}
			}
			//return lyndon;
			return right_point;
		}
		//求这个字符串的所有前缀字符串中的最大字典序子串
		//子串的左端点就是数组 l[]
		//可以证明其右端点就是 子串最右端 即 i
		vector<int> duval_getMaxOrderSubstringLeftPoint(string const& s) {
			int len = s.size(), i = 1;
			vector<int>l(len + 5);
			while (i < len) {
				int j = i + 1, k = i;
				if (!l[i]) l[i] = i;
				//cout << i << ' ';
				while (j < len && s[k] >= s[j]) {
					if (!l[j]) l[j] = i;
					if (s[k] == s[j]) k++;
					else k = i;
					j++;
				}
				while (i <= k) i += j - k;
			}
			return l;
		}
		// 最小表示法
		string minCyclicString(string s) {
			s += s;
			int len = s.size();
			int i = 0, ans = 0;
			while (i < len / 2) {
				ans = i;
				int j = i + 1, k = i;
				while (j < len && s[k] <= s[j]) {
					if (s[k] < s[j]) k = i;
					else k++;
					j++;
				}
				while (i <= k) i += j - k;
			}
			return s.substr(ans, len / 2);
		}
	};
};


void solve() {


}




signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	//freopen("wrt.in", "r", stdin);
	//freopen("out.out", "w", stdout);

	signed T = 1;
	//scanf("%d", &T);
	//cin >> T;
	while (T--) {
		solve();
	}
	return 0;
}