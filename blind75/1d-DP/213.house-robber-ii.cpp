/*
 * @lc app=leetcode id=213 lang=cpp
 *
 * [213] House Robber II
 */

// @lc code=start
class Solution {
   public:
    int robmax(vector<int>& nums, int l, int r) {
        if (r - l <= 1)
            return nums[l];
        int n = nums.size();
        vector<int> dp(n + 2);
        int ans = -1e6;
        for (int i = l + 2; i < r + 2; ++i) {
            dp[i] = max(dp[i - 1], nums[i - 2] + dp[i - 2]);
            ans = max(ans, dp[i]);
        }
        return ans;
    }
    int rob(vector<int>& nums) {
        if (nums.size() <= 1)
            return nums.empty() ? 0 : nums[0];
        return max(robmax(nums, 0, nums.size() - 1), robmax(nums, 1, nums.size()));
    }
};
// @lc code=end
