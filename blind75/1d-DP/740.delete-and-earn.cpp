/*
 * @lc app=leetcode id=740 lang=cpp
 *
 * [740] Delete and Earn
 */

// @lc code=start
class Solution {
   public:
    int deleteAndEarn(vector<int>& nums) {
        int n = 1e4;
        vector<int> mp(n + 1);
        vector<int> dp(n + 2);
        for (int i : nums)
            mp[i] += i;
        dp[1] = mp[1];
        for (int i = 2; i < n + 1; ++i) {
            dp[i] = max(dp[i - 1], dp[i - 2] + mp[i]);
        }
        return dp[n];
    }
};
// @lc code=end
