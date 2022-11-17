/*
 * @lc app=leetcode id=332 lang=cpp
 *
 * [332] Reconstruct Itinerary
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
   public:
    vector<string> findItinerary(vector<vector<string>> &tickets) {
        unordered_map<string, multiset<string>> mp;
        vector<string> ans;
        for (auto &ticket : tickets) {
            mp[ticket[0]].insert(ticket[1]);
        }
        dfs(mp, "JFK", ans);
        reverse(ans.begin(), ans.end());
        return ans;
    }
    void dfs(unordered_map<string, multiset<string>> &mp, string src, vector<string> &ans) {
        while (!mp[src].empty()) {
            string s = *mp[src].begin();
            mp[src].erase(mp[src].begin());
            dfs(mp, s, ans);
        }
        ans.push_back(src);
    }
};
// @lc code=end
