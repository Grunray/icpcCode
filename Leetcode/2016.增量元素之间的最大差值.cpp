// @before-stub-for-debug-begin
#include<bits/stdc++.h>
using namespace std;
// @before-stub-for-debug-end
/*
 * @lc app=leetcode.cn id=2016 lang=cpp
 *
 * [2016] 增量元素之间的最大差值
 */

// @lc code=start
class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int maxn = -1;

        for(int l = 0, r = 1; l < r && r < nums.size(); r++) {
            if(nums[l] < nums[r]) {
                maxn = max(maxn, nums[r] - nums[l]);
            }
            else if(nums[r] <= nums[l]) l = r;
        }

        return maxn;
    }
};
// @lc code=end

