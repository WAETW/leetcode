/*
 * @lc app=leetcode id=138 lang=cpp
 *
 * [138] Copy List with Random Pointer
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
   public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> mp;
        Node* tmp = head;
        while (tmp) {
            mp[tmp] = new Node(tmp->val);
            tmp = tmp->next;
        }
        tmp = head;
        while (tmp) {
            mp[tmp]->next = mp[tmp->next];
            mp[tmp]->random = mp[tmp->random];
            tmp = tmp->next;
        }
        return mp[head];
    }
};
// @lc code=end
