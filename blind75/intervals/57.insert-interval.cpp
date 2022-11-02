/*
 * @lc app=leetcode id=57 lang=cpp
 *
 * [57] Insert Interval
 */

// @lc code=start
class Solution {
   public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size();
        int curr = 0;
        if (n == 0) {
            intervals.push_back(newInterval);
            return intervals;
        }
        vector<vector<int>> ans;
        for (int i = 0; i < n; ++i) {
            if (intervals[i][0] <= newInterval[1] && intervals[i][1] >= newInterval[0]) {
                newInterval[0] = min(newInterval[0], intervals[i][0]);
                newInterval[1] = max(newInterval[1], intervals[i][1]);
            } else if (intervals[i][1] < newInterval[0]) {
                ++curr;
                ans.push_back(intervals[i]);
            } else if (intervals[i][0] > newInterval[1]) {
                ans.push_back(intervals[i]);
            }
        }
        ans.insert(ans.begin() + curr, newInterval);
        return ans;
    }
};
// @lc code=end
