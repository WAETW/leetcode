/*
 * @lc app=leetcode id=152 lang=cpp
 *
 * [152] Maximum Product Subarray
 */

// @lc code=start
class Solution
{
public:
    int maxProduct(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> maxdp(n + 1);
        vector<int> mindp(n + 1);
        maxdp[0] = mindp[0] = nums[0];
        int ans = nums[0];
        for (int i = 1; i < n; ++i)
        {
            maxdp[i] = max(maxdp[i - 1] * nums[i], max(nums[i], nums[i] * mindp[i - 1]));
            mindp[i] = min(maxdp[i - 1] * nums[i], min(nums[i], nums[i] * mindp[i - 1]));
            ans = max(ans, maxdp[i]);
        }
        return ans;
    }
};
// @lc code=end
