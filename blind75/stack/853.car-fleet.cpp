/*
 * @lc app=leetcode id=853 lang=cpp
 *
 * [853] Car Fleet
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
   public:
    static bool comp(const pair<int, int>& p1, const pair<int, int>& p2) {
        return p1.first > p2.first;
    }
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, float>> adj;
        int n = position.size();
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            adj.push_back(make_pair(position[i], (float)(target - position[i]) / speed[i]));
        }
        sort(adj.begin(), adj.end(), comp);
        float tmp = -1;
        for (auto& a : adj) {
            if (a.second > tmp) {
                tmp = a.second;
                ans++;
            }
        }
        return ans;
    }
};
// @lc code=end
