/*
 * @lc app=leetcode id=124 lang=cpp
 *
 * [124] Binary Tree Maximum Path Sum
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
    int max_path = -1e4;
    int dfs(TreeNode* root) {
        if (!root)
            return 0;
        int sum = root->val;
        int l = dfs(root->left);
        int r = dfs(root->right);
        if (l > 0)
            sum += l;
        if (r > 0)
            sum += r;
        max_path = max(max_path, sum);
        if (max(l, r) > 0)
            return root->val + max(l, r);
        return root->val;
    }
    int maxPathSum(TreeNode* root) {
        dfs(root);
        return max_path;
    }
};
// @lc code=end
