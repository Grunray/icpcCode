#include<bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode.cn id=1513 lang=cpp
 *
 * [1513] 仅含 1 的子串数
 */

// @lc code=start
class Solution {
private:
    long long MODE = 1e9 + 7;
public:
    int numSub(string s) {
        vector<long long> v;

        long long ans = 0;
        for(auto ch : s) {
            if(ch == '1') ans++;
            else {
                v.push_back(ans);
                ans = 0;
            }
        }
        if(ans) v.push_back(ans);

        int res = 0;

        for(auto x : v) {
            long long temp = 0;
            if(x & 1) temp = ((x + 1) / 2 * x) % MODE;
            else temp = (x / 2 * (x + 1)) % MODE;
            res = (res + temp) % MODE;
        }

        return res;
    }
};
// @lc code=end

void solve() {

    string str; cin >> str;

    Solution sol;

    cout << sol.numSub(str) << '\n';

}

signed main() {

    int T = 1;
    // cin >> T;

    while(T--) {
        solve();
    }
    
    return 0;
}