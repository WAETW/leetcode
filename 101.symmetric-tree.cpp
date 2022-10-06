/*
 * @lc app=leetcode id=101 lang=cpp
 *
 * [101] Symmetric Tree
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        queue<TreeNode*> q;
        if(!root)
            return false;
        q.push(root->left);
        q.push(root->right);
        while (!q.empty())
        {
            TreeNode* currLeft = q.front();
            q.pop();
            TreeNode* currRight = q.front();
            q.pop();
            if(currLeft != currRight)
                return false;
            if(currLeft->left != NULL)
                q.push(currLeft->left);
            if(currRight->right != NULL)
                q.push(currRight->right);
            if(currLeft->right != NULL)
                q.push(currLeft->right);
            if(currRight->left != NULL)
                q.push(currRight->left);
        }
        return true;
    }
};
// @lc code=end

