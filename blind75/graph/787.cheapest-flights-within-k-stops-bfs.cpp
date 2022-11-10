/*
 * @lc app=leetcode id=787 lang=cpp
 *
 * [787] Cheapest Flights Within K Stops
 */

// @lc code=start
class Solution {
   public:
    int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int K) {
        int ans = INT_MAX;
        unordered_map<int, vector<pair<int, int>>> adj;
        queue<pair<int, int>> q;
        vector<int> dist(n, INT_MAX);  // using dist array to cache minimal cost
        for (int i = 0; i < flights.size(); ++i) {
            adj[flights[i][0]].push_back(make_pair(flights[i][1], flights[i][2]));
        }
        q.push(make_pair(src, 0));
        int step = 0;
        while (!q.empty()) {
            int sz = q.size();
            while (sz--) {
                auto curr = q.front().first;
                auto cost = q.front().second;
                q.pop();
                if (dist[curr] < cost)
                    continue;
                dist[curr] = cost;
                for (auto &i : adj[curr]) {  // adj dist = i.first adj cost = i.second;
                    if (cost + i.second > ans)
                        continue;
                    if (i.first == dst)
                        ans = min(ans, cost + i.second);
                    q.push(make_pair(i.first, cost + i.second));
                }
            }
            if (step++ >= K)
                break;
        }
        return ans == INT_MAX ? -1 : ans;
    }
};
// @lc code=end
