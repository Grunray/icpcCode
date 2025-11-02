#include<bits/stdc++.h>
#include<vector>
using namespace std;

class Tree
{
    struct Node {
        int val;
        Node* children;
    };
    vector< vector<int> > levelOrder(Node* root) {
        if (!root) {
            return {};
        }
        vector<vector<int>> res;
        queue<Node*> q;
        q.push(root);
        while (!q.empty()) {
            int currentLevelSize = q.size();  // 当前层的节点个数
            res.push_back(vector<int>());
            for (int i = 0; i < currentLevelSize; ++i) {
                Node* cur = q.front();
                q.pop();
                res.back().push_back(cur->val);
                // for (Node* child : cur->children) {  // 把子节点都加入
                //     q.push(child);
                // }
            }
        }
        return res;
    }
};
