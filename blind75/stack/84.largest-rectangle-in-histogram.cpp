/*
 * @lc app=leetcode id=84 lang=cpp
 *
 * [84] Largest Rectangle in Histogram
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
   public:
    int largestRectangleArea(vector<int>& heights) {
        stack<pair<int, int>> st;
        int ans = 0;
        int n = heights.size();
        for (int i = 0; i < n; ++i) {
            int tmp = i;
            while (!st.empty() && st.top().first > heights[i]) {
                int index = st.top().second;
                ans = max(ans, st.top().first * (i - index));
                st.pop();
                tmp = index;
            }
            st.push(make_pair(heights[i], tmp));
        }
        while (!st.empty()) {
            int index = st.top().second;
            ans = max(ans, st.top().first * (n - index));
            st.pop();
        }
        return ans;
    }
};
// @lc code=end
