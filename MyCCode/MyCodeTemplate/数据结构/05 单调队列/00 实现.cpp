
/*
    
*/

#define _CRT_SECURE_NO_WARNINGS
#define itn int
#define PII pair<int, int>
#define PLI pair<long long, int>
#define fep(i, a, b) for(int i = (a); i >= (b); --i)
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
#include<bits/stdc++.h>
#include<unordered_map>
using ll = long long;
using ldou = long double;
using unll = unsigned long long;
using namespace std;

inline int read() {
    int x = 0, f = 1; char ch = getchar();
    while (ch < '0' || ch>'9') { if (ch == '-') f = -1; ch = getchar(); }
    while (ch >= '0' && ch <= '9') { x = x * 10 + ch - 48; ch = getchar(); }
    return x * f;
}

ll gcd(ll a, ll b) { // 最大公约数
    while (b ^= a ^= b ^= a %= b)
        ;
    return a;
}
ll lcm(ll a, ll b) { // 最小公倍数
    return a / gcd(a, b) * b;
}
ll qmi(ll m, ll k, ll p) { // 快速幂
    //求 m^k mod p，时间复杂度 O(logk)。
    //m为底数，k为幂
    ll res = 1 % p, t = m;
    while (k) {
        if (k & 1) res = res * t % p;
        t = t * t % p;
        k >>= 1;
    }
    return res;
}
unll qmi(unll m, unll k, unll p) { //龟速乘
    ll res = 0, t = m;
    while (k) {
        if (k & 1) res = (res + t) % p;
        k >>= 1;
        t = (t << 1) % p;
    }
    return res;
}

////////////////////////////////////////////////////////////////////////////////

ll n, m, k;

const int N = 2e6 + 50;
const ll INF = 1e9;
const ll MODE = ll(998244353);
const int dx[4] = { 1,-1, 0, 0 };
const int dy[4] = { 0, 0, 1,-1 };
//priority_queue<int> p;//这是一个大根堆q
//priority_queue<int, vector<int>, greater<int> >q;//这是一个小根堆q
//priority_queue<ll, vector<ll>, greater<ll> >pq; // 小根

int q[N], a[N];

void getmin() {  // 得到这个队列里的最小值，直接找到最后的就行了
    int head = 0, tail = -1;
    for (int i = 1; i < k; i++) {
        while (head <= tail && a[q[tail]] >= a[i]) tail--;
        q[++tail] = i;
    }
    for (int i = k; i <= n; i++) {
        while (head <= tail && a[q[tail]] >= a[i]) tail--;
        q[++tail] = i;
        while (q[head] <= i - k) head++;
        printf("%d ", a[q[head]]);
    }
}

void getmax() {  // 和上面同理
    int head = 0, tail = -1;
    for (int i = 1; i < k; i++) {
        while (head <= tail && a[q[tail]] <= a[i]) tail--;
        q[++tail] = i;
    }
    for (int i = k; i <= n; i++) {
        while (head <= tail && a[q[tail]] <= a[i]) tail--;
        q[++tail] = i;
        while (q[head] <= i - k) head++;
        printf("%d ", a[q[head]]);
    }
}

void solve() {

    cin >> n >> k;

    rep(i, 1, n) cin >> a[i];

    getmin();
    cout << '\n';
    getmax();
    cout << '\n';


}


signed main() {
    std::ios::sync_with_stdio(false); std::cin.tie(0), std::cout.tie(0);
    /*freopen("out.txt", "r", stdin);
    freopen("wrt.txt", "w", stdout);*/
    int TTT = 1; //cin >> TTT;
    while (TTT--) {
        solve();
    }
    /*while (cin >> n >> m) {
        solve();
    }*/

    return 0;
}