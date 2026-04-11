#include<bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode.cn id=460 lang=cpp
 *
 * [460] LFU 缓存
 */
// 一个链表存使用序列，队头是最近使用，队尾是最不经常使用
// 哈希表存使用频率，删除时也删除使用的频率
// @lc code=start
class LFUCache {
public:
    LFUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        if(ump.count(key)) {
            int freq = ump[key];
        }
    }
    
    void put(int key, int value) {
        
    }
    
private:
    struct Bucket
    {
        int freq;
        list<pair<int, int> > lp;
    };
private:
    int capacity;
    list<Bucket> ls;
    // freq -> bucket
    unordered_map<int, list<Bucket>::iterator> cache;
    // key -> freq
    unordered_map<int, int> ump;
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end

