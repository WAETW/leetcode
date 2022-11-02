/*
 * @lc app=leetcode id=55 lang=cpp
 *
 * [55] Jump Game
 */

// @lc code=start
class Solution {
   public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int max_j = 0;
        for (int i = 0; i < n; ++i) {
            if (i > max_j)
                return false;
            max_j = max(max_j, nums[i] + i);
        }
        return true;
    }
};
// @lc code=end
