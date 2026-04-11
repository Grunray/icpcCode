#include<bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode.cn id=146 lang=cpp
 *
 * [146] LRU 缓存
 */

// @lc code=start
class LRUCache {
private:
    int n;
    list<pair<int, int> > lp;
    unordered_map<int, list<pair<int, int> >::iterator> ump;
public:
    LRUCache(int capacity) {
        this->n = capacity;
    }
    
    int get(int key) {
        if(ump.count(key)) {
            int res = ump[key]->second;
            lp.erase(ump[key]);
            lp.push_front({key, res});
            ump[key] = lp.begin();
            return res;
        }
        else return -1;
    }
    
    void put(int key, int value) {
        if(ump.count(key)) {
            lp.erase(ump[key]);
            ump.erase(key);
        }
        else if(lp.size() >= n) {
            ump.erase(lp.back().first);
            lp.pop_back();
        }
        lp.push_front({key, value});
        ump[key] = lp.begin();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end

