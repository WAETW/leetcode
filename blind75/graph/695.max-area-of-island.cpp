#include "../../tools/utils.h"

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans = 0;
        for(int i = 0;i < grid.size();++i){
            for(int j = 0;j < grid[0].size();++j){
                if(grid[i][j]) {
                    int tmp = 0;
                    dfs(grid, i, j, tmp);
                    ans = max(ans, tmp);
                }
            }
        }
        return ans;
    }

    void dfs(vector<vector<int>> &grid, int x, int y, int &ans){
        if(x < 0 || y < 0 || x >= grid.size() || y >= grid[0].size() || grid[x][y] == 0)
            return;
        ++ans;
        grid[x][y] = 0;
        dfs(grid, x + 1, y, ans);
        dfs(grid, x - 1, y, ans);
        dfs(grid, x, y + 1, ans);
        dfs(grid, x, y - 1, ans);
    }
};

int main() {
    Solution s;
    vector<vector<int>> grid = {{0,0,1,0,0,0,0,1,0,0,0,0,0},{0,0,0,0,0,0,0,1,1,1,0,0,0},
                                {0,1,1,0,1,0,0,0,0,0,0,0,0},{0,1,0,0,1,1,0,0,1,0,1,0,0},
                                {0,1,0,0,1,1,0,0,1,1,1,0,0},{0,0,0,0,0,0,0,0,0,0,1,0,0},
                                {0,0,0,0,0,0,0,1,1,1,0,0,0},{0,0,0,0,0,0,0,1,1,0,0,0,0}
    };
    cout << s.maxAreaOfIsland(grid) <<"\n";
    return 0;
}