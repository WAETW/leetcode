/*
 * @lc app=leetcode id=74 lang=cpp
 *
 * [74] Search a 2D Matrix
 */

// @lc code=start
class Solution {
   public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int l = 0;
        int r = matrix[0].size();
        int n = matrix.size();
        for (int i = 0; i < n; ++i) {
            int l = 0;
            int r = matrix[i].size() - 1;
            while (l <= r) {
                int m = l + (r - l) / 2;
                if (matrix[i][m] == target)
                    return true;
                if (matrix[i][m] < target)
                    l = m + 1;
                else
                    r = m - 1;
            }
        }
        return false;
    }
};
// @lc code=end
