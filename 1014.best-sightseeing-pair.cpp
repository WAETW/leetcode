/*
 * @lc app=leetcode id=1014 lang=cpp
 *
 * [1014] Best Sightseeing Pair
 */

// @lc code=start
class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int n = values.size();
        int ans = 0;
        int tmp = values[0] + 0;
        for(int i = 1; i < n; ++i){
            ans = max(ans, tmp + values[i] - i);
            tmp = max(tmp, values[i] + i);
        }
        return ans;
    }
};
// @lc code=end

