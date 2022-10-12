/*
 * @lc app=leetcode id=297 lang=cpp
 *
 * [297] Serialize and Deserialize Binary Tree
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
   public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string s = "";
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* tmp = q.front();
            q.pop();
            if (tmp != nullptr) {
                s += to_string(tmp->val);
                s += ' ';
                if (!tmp->left) {
                    q.push(nullptr);
                } else
                    q.push(tmp->left);
                if (!tmp->right) {
                    q.push(nullptr);
                } else
                    q.push(tmp->right);
            } else {
                s += 'N';
                s += ' ';
            }
        }
        // cout << s << '\n';
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string s) {
        istringstream ss(s);
        string c;
        cout << c << '\n';
        ss >> c;
        if (c == "N")
            return nullptr;
        TreeNode* root = new TreeNode(stoi(c));
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* tmp = q.front();
            q.pop();
            ss >> c;
            if (!c.empty() && c != "N") {
                cout << c << '\n';
                tmp->left = new TreeNode(stoi(c));
                q.push(tmp->left);
            }
            ss >> c;
            if (!c.empty() && c != "N") {
                cout << c << '\n';
                tmp->right = new TreeNode(stoi(c));
                q.push(tmp->right);
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
// @lc code=end
