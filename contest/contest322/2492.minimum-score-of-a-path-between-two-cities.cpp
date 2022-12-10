class Solution {
   public:
    int minScore(int n, vector<vector<int>> &roads) {
        unordered_map<int, vector<pair<int, int>>> adj;
        int ans = 1e5;
        vector<int> visited(n + 1);
        queue<int> q;
        for (auto &road : roads) {
            adj[road[0]].push_back(make_pair(road[1], road[2]));
            adj[road[1]].push_back(make_pair(road[0], road[2]));
        }
        q.push(1);
        visited[1] = 1;
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            for (auto &a : adj[curr]) {
                if (!visited[a.first]) {
                    q.push(a.first);
                    visited[a.first] = 1;
                }
                ans = min(ans, a.second);
            }
        }
        return ans;
    }
};