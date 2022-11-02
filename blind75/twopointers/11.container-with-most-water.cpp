/*
 * @lc app=leetcode id=11 lang=cpp
 *
 * [11] Container With Most Water
 */

// @lc code=start
class Solution {
   public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int ans = 0;
        for (int i = 0, j = n - 1; i < j;) {
            ans = max(ans, min(height[i], height[j]) * (j - i));
            if (height[i] <= height[j])
                ++i;
            else
                --j;
        }
        return ans;
    }
};
// @lc code=end
