/*
 * @lc app=leetcode id=36 lang=cpp
 *
 * [36] Valid Sudoku
 */

// @lc code=start
class Solution {
   public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<vector<int>> col(9, vector<int>(9, 0));
        vector<vector<int>> row(9, vector<int>(9, 0));
        vector<vector<int>> nine(9, vector<int>(9, 0));
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] == '.')
                    continue;
                int a = (i / 3) * 3 + (j / 3);
                int num = board[i][j] - '0' - 1;
                if (col[i][num] == 1 || row[j][num] == 1 || nine[a][num] == 1)
                    return false;
                if (col[i][num] == 0)
                    col[i][num] = 1;
                if (row[j][num] == 0)
                    row[j][num] == 1;
                if (nine[a][num] == 0)
                    nine[a][num] == 1;
            }
        }
        return true;
    }
};
// @lc code=end
