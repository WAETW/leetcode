/*
 * @lc app=leetcode id=121 lang=cpp
 *
 * [121] Best Time to Buy and Sell Stock
 */

// @lc code=start
class Solution {
   public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        int mxn = 1e4;
        for (int i : prices) {
            mxn = min(mxn, i);
            ans = max(ans, i - mxn);
        }
        return ans;
    }
};
// @lc code=end
