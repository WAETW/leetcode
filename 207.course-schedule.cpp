/*
 * @lc app=leetcode id=207 lang=cpp
 *
 * [207] Course Schedule
 */

// @lc code=start
class Solution {
   public:
    void dfs(vector<vector<int>> &adj, vector<int> &visited, int num, int s, bool &cycle) {
        if (visited[s] == 1) {
            cycle = true;
            return;
        }
        if (visited[s] == 2) {
            return;
        }
        visited[s] = 1;
        for (int i = 0; i < num; ++i) {
            if (adj[i][s] == 1)
                dfs(adj, visited, num, i, cycle);
        }
        visited[s] = 2;
    }
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites) {
        vector<vector<int>> adj(numCourses, vector<int>(numCourses, 0));
        vector<int> visited(numCourses, 0);
        bool cycle = false;
        for (auto &a : prerequisites) {
            adj[a[0]][a[1]] = 1;
        }
        for (int i = 0; i < numCourses; ++i) {
            if (visited[i] != 1)
                dfs(adj, visited, numCourses, i, cycle);
        }
        if (cycle)
            return false;
        return true;
    }
};
// @lc code=end
