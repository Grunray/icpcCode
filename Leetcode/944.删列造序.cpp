#include<bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode.cn id=944 lang=cpp
 *
 * [944] 删列造序
 */

// @lc code=start
class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int ans = 0;
        int len = strs[0].length();
        int n = strs.size();

        for(int j = 0; j < len; j++) {
            for(int i = 0; i < n - 1; i++) {
                if(strs[i][j] > strs[i + 1][j]) {
                    ans++;
                    break;
                }
            }
        }

        return ans;
    }
};
// @lc code=end

