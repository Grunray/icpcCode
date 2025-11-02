/*
假设来到当前节点 cur，开始时来到根节点位置。

    如果 cur 为空时遍历停止，否则进行以下过程。
    如果 cur 没有左子树，cur 向右移动（cur = cur->right）。
    如果 cur 有左子树，找到左子树上最右的节点，记为 mostRight。
    如果 mostRight 的 right 指针指向空，让其指向 cur，然后 cur 向左移动（cur = cur->left）。
    如果 mostRight 的 right 指针指向 cur，将其修改为 null，然后 cur 向右移动（cur = cur->right）。
*/
#include<bits/stdc++.h>
using namespace std;

class moriss
{
public:
    struct TreeNode
    {
        int val;
        TreeNode* left;
        TreeNode* right;
    };

public:
    void morris(TreeNode* root) {
        TreeNode* cur = root;
        while (cur) {
            if (!cur->left) {
                // 如果当前节点没有左子节点，则输出当前节点的值并进入右子树
                std::cout << cur->val << " ";
                cur = cur->right;
                continue;
            }
            // 找到当前节点的左子树的最右节点
            TreeNode* mostRight = cur->left;
            while (mostRight->right && mostRight->right != cur) {
                mostRight = mostRight->right;
            }
            if (!mostRight->right) {
                // 如果最右节点的right指针为空，将其指向当前节点，并进入左子树
                mostRight->right = cur;
                cur = cur->left;
            } else {
                // 如果最右节点的right指针指向当前节点，说明左子树已经遍历完毕，输出当前节点的值并进入右子树
                mostRight->right = nullptr;
                std::cout << cur->val << " ";
                cur = cur->right;
            }
        }
    }
};