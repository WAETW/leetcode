/*
 * @lc app=leetcode id=39 lang=cpp
 *
 * [39] Combination Sum
 */

// @lc code=start
class Solution {
   public:
    void dfs(vector<int> &cand, vector<vector<int>> &ans, vector<int> &v, int target, int curr) {
        if (target < 0)
            return;
        if (target == 0)
            ans.push_back(v);
        for (int i = curr; i < cand.size(); ++i) {
            v.push_back(cand[i]);
            dfs(cand, ans, v, target - cand[i], i);
            v.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
        vector<vector<int>> ans;
        vector<int> v;
        dfs(candidates, ans, v, target, 0);
        return ans;
    }
};
// @lc code=end
