#include<bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 */

// @lc code=start
class Solution {
public:
    string longestPalindrome(string s) {
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
    pair<vector<int>, vector<int> > MANACHER(string s) { // 算法本体
        int len = s.length();
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
};
// @lc code=end


void solve() {

    string str; cin >> str;

    Solution s1;

    cout << s1.longestPalindrome(str) << '\n';

   

    


}

signed main() {

    int T = 1;
    // cin >> T;

    while(T--) {
        solve();
    }
    
    return 0;
}