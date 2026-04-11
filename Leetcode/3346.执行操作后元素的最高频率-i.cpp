// @before-stub-for-debug-begin
#include<bits/stdc++.h>

using namespace std;
// @before-stub-for-debug-end
/*
 * @lc app=leetcode.cn id=3346 lang=cpp
 *
 * [3346] 执行操作后元素的最高频率 I
 */

// @lc code=start
class Solution {
public:
    int binary(vector<int>& nums, int x, int l, int r) {
        while(l < r) {
            int mid = (l + r) / 2;
            if(nums[mid] <= x) {
                r = mid - 1;
            }
            else {
                l = mid + 1;
            }
        }
        return l;
    }
    int maxFrequency(vector<int>& nums, int k, int numOperations) {

        int n = nums.size();
        sort(nums.begin(), nums.end());

        map<int, int> mp;
        for(auto x : nums) mp[x]++;

        int maxn = 0;
        int l = 0, r = 0;
        // for(int i = 0; i < nums.size(); i++) {
        for(int i = nums[0] - k; i <= nums.back() + k; i++) {
            // min(x - k <= x <= x + k, k)
            // min(pos(x + k) => r - pos(x - k)=> l, k)
            // int l = binary(nums, nums[i] - k, 0, i);
            // int r = binary(nums, nums[i] + k, i + 1, nums.size() - 1);
            while(l < n && i - nums[l] > k) l++;
            while(r < n && nums[r] - i <= k) r++;
            maxn = max(maxn, min(numOperations + mp[i], r - l));
        }

        return maxn;
    }
};
// @lc code=end

