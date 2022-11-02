/*
 * @lc app=leetcode id=105 lang=cpp
 *
 * [105] Construct Binary Tree from Preorder and Inorder Traversal
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
    TreeNode* build(vector<int>& inorder, vector<int>& preorder, unordered_map<int, int>& mp, int istart, int iend, int pstart, int pend) {
        if (istart > iend || pstart > preorder.size())
            return NULL;
        TreeNode* root = new TreeNode(preorder[pstart]);
        int rootindex = mp[preorder[pstart]];
        root->left = build(inorder, preorder, mp, istart, rootindex - 1, pstart + 1, pstart + rootindex - istart);
        root->right = build(inorder, preorder, mp, rootindex + 1, iend, pstart + rootindex - istart + 1, pend);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> mp;
        for (int i = 0; i < inorder.size(); ++i) {
            mp[inorder[i]] = i;
        }
        return build(inorder, preorder, mp, 0, inorder.size() - 1, 0, preorder.size() - 1);
    }
};
// @lc code=end
