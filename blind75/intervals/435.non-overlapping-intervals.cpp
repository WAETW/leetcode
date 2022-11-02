/*
 * @lc app=leetcode id=435 lang=cpp
 *
 * [435] Non-overlapping Intervals
 */

// @lc code=start
class Solution {
   public:
    static bool comp(const vector<int> &v1, const vector<int> &v2) {
        return v1[0] < v2[0];
    }
    int eraseOverlapIntervals(vector<vector<int>> &intervals) {
        int n = intervals.size();
        int ans = 0;
        if (n == 1)
            return ans;
        sort(intervals.begin(), intervals.end(), comp);
        for (int i = 0; i < n - 1; ++i) {
            if (intervals[i][1] > intervals[i + 1][0]) {
                if (intervals[i][1] < intervals[i + 1][1]) {
                    intervals[i + 1] = intervals[i];
                }
                ans++;
            }
        }
        return ans;
    }
};
// @lc code=end
