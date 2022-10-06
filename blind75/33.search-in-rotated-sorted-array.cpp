/*
 * @lc app=leetcode id=33 lang=cpp
 *
 * [33] Search in Rotated Sorted Array
 */

// @lc code=start
class Solution {
   public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        while (left <= right) {
            int middle = left + (right - left) / 2;
            if (nums[middle] == target)
                return middle;
            if (nums[middle] >= nums[left]) {                        //左邊為rotated sort array 右邊為sort array
                if (target <= nums[middle] && target >= nums[left])  // target 在rotated sort array
                    right = middle - 1;
                else
                    left = middle + 1;
            } else {
                if (target >= nums[middle] && target <= nums[right])
                    left = middle + 1;
                else
                    right = middle - 1;
            }
        }
        return -1;
    }
};
// @lc code=end
