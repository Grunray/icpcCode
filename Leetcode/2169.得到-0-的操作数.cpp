#include<bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode.cn id=2169 lang=cpp
 *
 * [2169] 得到 0 的操作数
 */

// @lc code=start
class Solution {
public:
    int countOperations(int num1, int num2) {
        int ans = 0;
        while(num1 && num2) {
            if(num1 >= num2) {
                int k = num1 / num2;
                num1 -= k * num2;
                ans += k;
            }
            else {
                int k = num2 / num1;
                num2 -= k * num1;
                ans += k;
            }
        }
        return ans;
    }
};
// @lc code=end

