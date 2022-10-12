/*
 * @lc app=leetcode id=133 lang=cpp
 *
 * [133] Clone Graph
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/
class Solution {
   public:
    Node* cloneGraph(Node* node) {
        if (!node)
            return nullptr;
        unordered_map<Node*, Node*> mp;
        Node* ans = new Node(node->val);
        mp[node] = ans;
        queue<Node*> q;
        q.push(node);
        while (!q.empty()) {
            Node* tmp = q.front();
            q.pop();
            for (auto& a : tmp->neighbors) {
                if (!mp.count(a)) {
                    mp[a] = new Node(a->val);
                    q.push(a);
                }
                mp[tmp]->neighbors.push_back(mp[a]);
            }
        }
        return ans;
    }
};
// @lc code=end
