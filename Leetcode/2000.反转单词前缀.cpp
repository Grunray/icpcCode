// @before-stub-for-debug-begin
#include<bits/stdc++.h>

using namespace std;
// @before-stub-for-debug-end
/*
 * @lc app=leetcode.cn id=2000 lang=cpp
 *
 * [2000] 反转单词前缀
 */

// @lc code=start
class Solution {
public:
    string reversePrefix(string word, char ch) {
        int pos = word.find(ch);
        if(pos == -1) return word;

        word.erase(pos, 1);
        
        reverse(word.begin(), word.begin() + pos);

        word = ch + word;

        return word;
    }
};
// @lc code=end

