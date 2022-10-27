/*
 * @lc app=leetcode id=238 lang=cpp
 *
 * [238] Product of Array Except Self
 */

// @lc code=start
class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> prefix(n, 1);
        vector<int> postfix(n, 1);
        vector<int> ans;
        for (int i = 1, j = n - 1; i<n, j> 0; ++i, --j)
        {
            prefix[i] = prefix[i - 1] * nums[i - 1];
            postfix[i] = postfix[i - 1] * nums[j];
        }
        for (int i = 0, j = n - 1; i <= n, j >= 0; ++i, --j)
        {
            ans.push_back(postfix[j] * prefix[i]);
        }
        return ans;
    }
};
// @lc code=end
