/*
 * @lc app=leetcode id=198 lang=cpp
 *
 * [198] House Robber
 */

// @lc code=start
class Solution {
   public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n + 2);
        int ans = -1e6;
        for (int i = 2; i < n + 2; ++i) {
            dp[i] = max(dp[i - 1], nums[i - 2] + dp[i - 2]);
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};
// @lc code=end
