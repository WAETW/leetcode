/*
 * @lc app=leetcode id=2 lang=cpp
 *
 * [2] Add Two Numbers
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
        int carry = 0;
        ListNode* tmp = new ListNode(0);
        ListNode* ans = tmp;
        while (l1 || l2) {
            if (l1 && l2) {
                int sum = l1->val + l2->val + carry;
                carry = sum / 10;
                tmp->next = new ListNode(sum % 10);
                l1 = l1->next;
                l2 = l2->next;
                tmp = tmp->next;
            }
            if (l1 && !l2) {
                int sum = l1->val + carry;
                carry = sum / 10;
                tmp->next = new ListNode(sum % 10);
                l1 = l1->next;
                tmp = tmp->next;
            }
            if (!l1 && l2) {
                int sum = l2->val + carry;
                carry = sum / 10;
                tmp->next = new ListNode(sum % 10);
                l2 = l2->next;
                tmp = tmp->next;
            }
        }
        if (carry)
            tmp->next = new ListNode(1);
        return ans->next;
    }
};
// @lc code=end
