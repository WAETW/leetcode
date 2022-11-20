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
// BST find O(n) * query(n) ~ O(n^2) = 1e12 O(n ~ nlogn)
//  class Solution {
//  public:
//      vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {
//          vector<vector<int>> res;
//          for(auto a:queries){
//              int maxN = -1;
//              int minN = -1;
//              dfs(root, a, maxN, minN);
//              res.push_back({minN, maxN});
//          }
//          return res;
//      }
//      void dfs(TreeNode* root, int &target, int &maxN, int &minN){
//          if(!root)
//              return;
//          if(root->val == target){
//              minN = target;
//              maxN = target;
//              return;
//          }
//           if(root->val > target){
//              maxN = root->val;
//              dfs(root->left, target, maxN, minN);
//          }
//          else {
//              minN = root->val;
//              dfs(root->right, target, maxN, minN);
//          }
//      }
//  };
//  BST find O(n) * query(n) ~ O(n^2) = 1e12 O(n ~ nlogn) > TLE?
//  class Solution {
//  public:
//      vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {
//          vector<vector<int>> res;
//          for(auto a:queries){
//              vector<int> key = {-1, -1};
//              vector<int> diff = {INT_MAX, INT_MAX};
//              dfs(root, a, diff, key);
//              res.push_back(key);
//          }
//          return res;
//      }
//      void dfs(TreeNode* root, int &target, vector<int> &diff, vector<int> &key){
//          if(!root)
//              return;
//          if(root->val == target){
//              key[0] = target;
//              key[1] = target;
//              return;
//          }
//           if(root->val > target){
//              if(diff[1] > root->val - target){
//                  diff[1] = abs(target - root->val);
//                  key[1] = root->val;
//              }
//              else if(diff[1] < root->val - target){
//                  return;
//              }
//          }
//          else if(root->val < target){
//              if(diff[0] > target - root->val){
//                  diff[0] = abs(target - root->val);
//                  key[0] = root->val;
//              }
//              else if(diff[0] < target - root->val){
//                  return;
//              }
//          }
//          if(root->val > target){
//              dfs(root->left, target, diff, key);
//          }
//          else if(root->val < target){
//              dfs(root->right, target, diff, key);
//          }
//      }
//  };
//  Inorder Traversal + binary search O(qlongn)
class Solution {
   public:
    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {
        vector<vector<int>> res;
        vector<int> val;
        dfs(root, val);
        for (auto& a : queries) {
            int minN = -1;
            int maxN = -1;
            auto min_it = upper_bound(val.begin(), val.end(), a);
            if (min_it != val.begin())
                minN = *prev(min_it);
            auto max_it = lower_bound(val.begin(), val.end(), a);
            if (max_it != val.end())
                maxN = *max_it;
            res.push_back({minN, maxN});
        }
        return res;
    }
    void dfs(TreeNode* root, vector<int>& val) {
        if (!root)
            return;
        dfs(root->left, val);
        val.emplace_back(root->val);
        dfs(root->right, val);
    }
};