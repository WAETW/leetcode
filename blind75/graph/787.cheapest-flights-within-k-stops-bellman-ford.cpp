/*
 * @lc app=leetcode id=787 lang=cpp
 *
 * [787] Cheapest Flights Within K Stops
 */

// @lc code=start
class Solution {
   public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> dist(n, INT_MAX);  // using dist array to cache minimal cost
        dist[src] = 0;
        for (int i = 0; i <= k; ++i) {
            vector<int> tmp(dist);
            for (auto a : flights) {
                if (dist[a[0]] == INT_MAX)
                    continue;
                tmp[a[1]] = min(tmp[a[1]], dist[a[0]] + a[2]);
            }
            dist = tmp;
        }
        return dist[dst] == INT_MAX ? -1 : dist[dst];
    }
};
// @lc code=end
