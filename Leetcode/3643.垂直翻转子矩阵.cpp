#include<bits/stdc++.h>
using namespace std;
int m, n;

/*
 * @lc app=leetcode.cn id=3643 lang=cpp
 *
 * [3643] 垂直翻转子矩阵
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        for(int i = y; i < y + k; i++)
            for(int j = 0; j < k / 2; j++)
                swap(grid[x + j][i], grid[x + k - 1 - j][i]);

        return grid;
    }
};
// @lc code=end

void solve() {

    int x, y, k;


    cin >> m >> n;

    vector<vector<int> > grid(m, vector<int>(n, 0));


    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    cin >> x >> y >> k;

    Solution s1;
    s1.reverseSubmatrix(grid, x , y, k);


}

signed main() {

    int T = 1;
    // cin >> T;

    while(T--) {
        solve();
    }
    
    return 0;
}

