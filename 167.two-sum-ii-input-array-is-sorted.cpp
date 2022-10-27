/*
 * @lc app=leetcode id=167 lang=cpp
 *
 * [167] Two Sum II - Input Array Is Sorted
 */

// @lc code=start
class Solution
{
public:
    vector<int> twoSum(vector<int> &numbers, int target)
    {
        int n = numbers.size();
        for (int i = 0, j = n - 1; i < j;)
        {
            int sum = numbers[i] + numbers[j];
            if (target == sum)
            {
                return {i + 1, j + 1};
            }
            if (sum > target)
            {
                --j;
            }
            else if (sum < target)
            {
                ++i;
            }
        }
        return {-1, -1};
    }
};
// @lc code=end
