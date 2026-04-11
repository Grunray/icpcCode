#include<bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode.cn id=3637 lang=cpp
 *
 * [3637] 三段式数组 I
 */

// @lc code=start
class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int n = nums.size();

        // if(n <= 3) {
        //     return false;
        // }

        int i = 0;
        int flag = 0;
        int ans = 3;
        
        while(ans--) {
            int temp = i;
            if(!flag) {
                for(; i < n - 1; i++) {
                    if(nums[i] >= nums[i + 1]) break;
                }
            }
            else {
                for(; i < n - 1; i++) {
                    if(nums[i] <= nums[i + 1]) break;
                }
            }
            flag = 1 - flag;
            if(i - temp < 1) return false;
        }

        if(i != n - 1) return false;
        

        return true;
    }
};
// @lc code=end
void solve() {
    vector<int> v;
    int n; cin >> n;

    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        v.push_back(x);
    }

    Solution s1;

    cout << s1.isTrionic(v) << '\n';



}

signed main() {

    int T = 1;
    // cin >> T;

    while(T--) {
        solve();
    }
    
    return 0;
}
