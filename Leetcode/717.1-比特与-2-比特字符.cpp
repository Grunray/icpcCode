#include<bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode.cn id=717 lang=cpp
 *
 * [717] 1 比特与 2 比特字符
 */

// @lc code=start
class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        if(bits.size() == 1) 
            return true;
        
        int n = bits.size();
        stack<int> stk;
        
        for(int i = 0; i < bits.size(); i++) {
            if(!stk.empty() && bits[stk.top()] == 1) {
                stk.pop();
            }
            else {
                stk.push(i);
            }
        }

        
        return !stk.empty() && stk.top() == n - 1;
    }
};
// @lc code=end

