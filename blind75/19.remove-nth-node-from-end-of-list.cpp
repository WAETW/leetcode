/*
 * @lc app=leetcode id=19 lang=cpp
 *
 * [19] Remove Nth Node From End of List
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* ans = head;
        ListNode* tmp = head;
        int m = 1;
        while (tmp) {
            tmp = tmp->next;
            ++m;
        }
        m = abs(m - n - 1);
        if (m == 0) {
            ans = ans->next;
        }
        while (m > 1) {
            head = head->next;
            --m;
        }
        if (!head->next) {
            return nullptr;
        }
        if (head->next->next)
            head->next = head->next->next;
        else if (!head->next->next)
            head->next = nullptr;
        return ans;
    }
};
// @lc code=end
