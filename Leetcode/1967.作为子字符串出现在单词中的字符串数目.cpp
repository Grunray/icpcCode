// @before-stub-for-debug-begin
#include<bits/stdc++.h>

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=1967 lang=cpp
 *
 * [1967] 作为子字符串出现在单词中的字符串数目
 */

// @lc code=start
class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        map<string, int> mp;
        int res = 0;
        for(auto str : patterns) {
            if(word.find(str)) {
                res++;
            }
        }
        return res;
    }
};
// @lc code=end

