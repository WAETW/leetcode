/*
 * @lc app=leetcode id=739 lang=cpp
 *
 * [739] Daily Temperatures
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
   public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> ans(n);
        stack<pair<int, int>> st;
        for (int i = 0; i < n; ++i) {
            int curr_temp = temperatures[i];
            while (!st.empty() && curr_temp > st.top().first) {
                int index = st.top().second;
                st.pop();
                ans[index] = i - index;
            }
            st.push(make_pair(curr_temp, i));
        }
        return ans;
    }
};
// @lc code=end
