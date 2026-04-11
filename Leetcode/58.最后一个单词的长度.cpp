// @before-stub-for-debug-begin
#include<bits/stdc++.h>

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=58 lang=cpp
 *
 * [58] 最后一个单词的长度
 */

// @lc code=start
class Solution {
public:
    int lengthOfLastWord(string s) {
        int res = 0;
        int len = s.length();
        for(int i = len - 1; i >= 0; i--) {
            if(isspace(s[i])) {
                if(res) break;
                else continue;
            }
            else {
                res++;
            }
        }
        return res;
    }
};
// @lc code=end

