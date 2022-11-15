/*
 * @lc app=leetcode id=42 lang=cpp
 *
 * [42] Trapping Rain Water
 */

// @lc code=start
class Solution {
   public:
    int trap(vector<int>& height) {
        int l = 0;
        int r = height.size() - 1;
        int maxL = height[l];
        int maxR = height[r];
        int ans = 0;
        while (l < r) {
            if (maxL <= maxR) {
                ++l;
                maxL = max(maxL, height[l]);
                ans += maxL - height[l];
            } else {
                --r;
                maxR = max(maxR, height[r]);
                ans += maxR - height[r];
            }
        }
        return ans;
    }
};
// @lc code=end
