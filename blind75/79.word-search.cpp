/*
 * @lc app=leetcode id=79 lang=cpp
 *
 * [79] Word Search
 */

// @lc code=start
class Solution {
   public:
    bool dfs(vector<vector<char>>& board, vector<vector<bool>>& visited, int index, string word, int i, int j) {
        if (index == word.size())
            return true;
        if (board.size() > i && board[i].size() > j && i >= 0 && j >= 0 && !visited[i][j] && word[index] == board[i][j]) {
            visited[i][j] = true;
            if (dfs(board, visited, index + 1, word, i + 1, j))
                return true;
            if (dfs(board, visited, index + 1, word, i - 1, j))
                return true;
            if (dfs(board, visited, index + 1, word, i, j + 1))
                return true;
            if (dfs(board, visited, index + 1, word, i, j - 1))
                return true;
            visited[i][j] = false;
        }
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        bool ans = false;
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (dfs(board, visited, 0, word, i, j))
                    return true;
            }
        }
        return false;
    }
};
// @lc code=end
