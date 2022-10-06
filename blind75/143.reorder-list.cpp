/*
 * @lc app=leetcode id=143 lang=cpp
 *
 * [143] Reorder List
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
#include "bits/stdc++.h"
using namespace std;
class Solution {
   public:
    void reorderList(ListNode* head) {
        ListNode* curr = head;
        stack<ListNode*> st;
        if (!head || !head->next || !head->next->next)
            return;
        while (head) {
            st.push(head);
            head = head->next;
        }
        int n = ((int)st.size() - 1) / 2;
        while (n-- > 0) {
            ListNode* tmp = curr->next;
            curr->next = st.top();
            st.pop();
            curr->next->next = tmp;
            curr = tmp;
        }
        st.top()->next = NULL;
    }
};
// @lc code=end
