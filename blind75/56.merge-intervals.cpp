/*
 * @lc app=leetcode id=56 lang=cpp
 *
 * [56] Merge Intervals
 */

// @lc code=start
class Solution {
   public:
    static bool comp(const vector<int>& v1, const vector<int>& v2) {
        return v1[0] < v2[0];
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), comp);
        vector<vector<int>> ans;
        int n = intervals.size();
        int l = intervals[0][0];
        int r = intervals[0][1];
        for (int i = 1; i < n; ++i) {
            if (intervals[i][0] <= r) {
                if (intervals[i][1] > r) {
                    r = intervals[i][1];
                }
            } else {
                ans.push_back({l, r});
                l = intervals[i][0];
                r = intervals[i][1];
            }
        }
        ans.push_back({l, r});
        return ans;
    }
};
// @lc code=end
