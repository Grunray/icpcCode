
// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        bool end1 = false, end2 = false;
        int sum = 0;
        ListNode* head = new ListNode(0);
        ListNode* res = head;

        while(1) {
            if(end1 && end2) break;

            if(!end1) {
                sum += l1->val;
                if(l1->next == nullptr) end1 = true;
                l1 = l1->next;
            }
            if(!end2) {
                sum += l2->val;
                if(l2->next == nullptr) end2 = true;
                l2 = l2->next;
            }
            
            res->next = new ListNode(sum % 10);
            res = res->next;

            sum /= 10;
        }

        if(sum) {
            res->next = new ListNode(sum);
            res = res->next;
        }

        return head->next;
    }
};
// @lc code=end

