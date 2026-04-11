#include<bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode.cn id=2424 lang=cpp
 *
 * [2424] 最长上传前缀
 */

// @lc code=start
class LUPrefix {
private:
    int n;
    int back;
    vector<bool> vb;
public:
    LUPrefix(int n) {
        this->n = n;
        this->back = 0;
        this->vb.resize(n + 1);
        // vb[back] = true;
    }
    
    void upload(int video) {
        vb[video - 1] = true;
        while(back < n && vb[back]) {
            back++;
        }
    }
    
    int longest() {
        return back;
    }
};

/**
 * Your LUPrefix object will be instantiated and called as such:
 * LUPrefix* obj = new LUPrefix(n);
 * obj->upload(video);
 * int param_2 = obj->longest();
 */
// @lc code=end