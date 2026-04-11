// @before-stub-for-debug-begin
#include<bits/stdc++.h>

using namespace std;
// @before-stub-for-debug-end
/*
 * @lc app=leetcode.cn id=2785 lang=cpp
 *
 * [2785] 将字符串中的元音字母排序
 */

// @lc code=start
class Solution {
public:
    string sortVowels(string s) {
        string t = s;
        string temp;

        map<char, bool> mp;
        mp['a'] = 1; mp['e'] = 1; mp['i'] = 1; mp['o'] = 1; mp['u'] = 1;
        mp['A'] = 1; mp['E'] = 1; mp['I'] = 1; mp['O'] = 1; mp['U'] = 1;

        for(int i = 0; i < s.length(); i++) {
            if(mp[s[i]]) {
                t[i] = ' ';
                temp.push_back(s[i]);
            }
        }

        sort(temp.begin(), temp.end());

        for(int i = 0, j = 0; i < t.length() && j < temp.size(); i++) {
            if(isspace(t[i])) {
                t[i] = temp[j++];
            }
        }

        return t;
    }
};
// @lc code=end

