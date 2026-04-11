#include<bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode.cn id=762 lang=cpp
 *
 * [762] 二进制表示中质数个计算置位
 */

// @lc code=start
class Solution {
public:
    int countPrimeSetBits(int left, int right) {

        setPrime();

        int res = 0;
        for(int i = left; i <= right; i++) {
            int now = i;
            int ans = 0;

            string str;
            while(now) {
                str += int(now & 1) + '0';
                if(now & 1) ans++;
                now >>= 1;
            }
            if(isPrime[ans]) res++;

        }
        return res;
    }

    void setPrime() {
        isPrime.resize(32, 0);
        for(int i = 3; i < 32; i += 2)
            isPrime[i] = true;
        isPrime[2] = true;

        for(int i = 3; i < 32; i += 2) {
            for(int j = 2; j * j <= i; j++) {
                if(i % j == 0) {
                    isPrime[i] = false;
                    break;
                }
            }
        }
    }
private:
    vector<bool> isPrime;
};
// @lc code=end
void solve() {

    int l, r; cin >> l >> r;

    Solution s1;
    cout << s1.countPrimeSetBits(l, r) << '\n';

}

signed main() {

    int T = 1;
    // cin >> T;

    while(T--) {
        solve();
    }
    
    return 0;
}
