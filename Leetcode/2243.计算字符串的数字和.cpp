#include<bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode.cn id=2243 lang=cpp
 *
 * [2243] 计算字符串的数字和
 */

// @lc code=start
class Solution {
public:
    string digitSum(string s, int k) {
        
        vector<char> vc;
        for(auto ch : s) vc.push_back(ch);

        while(vc.size() > k) {
            vector<char> temp;

            int i = 0;
            for(i; i < vc.size(); i += k) {
                int sum = 0;
                for(int j = i; j < vc.size() && j < i + k; j++) {
                    sum += int(vc[j] - '0');
                }
                string tsum = to_string(sum);
                // while(tsum.size() < k) {
                //     tsum = '0' + tsum;
                // }
                for(auto tch : tsum) temp.push_back(tch);
            }

            vc = temp;
        }

        string res;
        for(auto ch : vc) res += ch;

        return res;
    }
};
// @lc code=end

