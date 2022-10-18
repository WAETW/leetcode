/*
 * @lc app=leetcode id=417 lang=cpp
 *
 * [417] Pacific Atlantic Water Flow
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>> &heights)
    {
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<int>> atl(n, vector<int>(m));
        vector<vector<int>> pac(n, vector<int>(m));
        vector<vector<int>> ans;
        for (int i = 0; i < n; ++i)
        {
            dfs(heights, atl, i, 0, n, m);
            dfs(heights, pac, i, m - 1, n, m);
        }
        for (int i = 0; i < m; ++i)
        {
            dfs(heights, atl, 0, i, n, m);
            dfs(heights, pac, n - 1, i, n, m);
        }
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                if (atl[i][j] && pac[i][j])
                    ans.push_back({i, j});
            }
        }
        return ans;
    }
    void dfs(vector<vector<int>> &heights, vector<vector<int>> &visited, int x, int y, int n, int m)
    {
        visited[x][y] = 1;
        if (x > 0 && !visited[x - 1][y] && heights[x - 1][y] >= heights[x][y])
            dfs(heights, visited, x - 1, y, n, m);
        if (y > 0 && !visited[x][y - 1] && heights[x][y - 1] >= heights[x][y])
            dfs(heights, visited, x, y - 1, n, m);
        if (x < n - 1 && !visited[x + 1][y] && heights[x + 1][y] >= heights[x][y])
            dfs(heights, visited, x + 1, y, n, m);
        if (y < m - 1 && !visited[x][y + 1] && heights[x][y + 1] >= heights[x][y])
            dfs(heights, visited, x, y + 1, n, m);
    }
};
// @lc code=end
