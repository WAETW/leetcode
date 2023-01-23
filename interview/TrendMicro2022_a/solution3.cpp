//
// Created by WAE on 2022/12/20.
//
#include "../../tools/utils.h"

class Solution {
public:
    void dfs(vector<vector<int>> &board, int &tmp,int x, int y){
        if(x < 0 || y < 0 || board.size() <= x || board[0].size() <=y || board[x][y] == 0)
            return;
        tmp++;
        board[x][y] = 0;
        dfs(board, tmp, x + 1, y);
        dfs(board, tmp, x, y + 1);
        dfs(board, tmp, x - 1, y);
        dfs(board, tmp, x, y -1);
    }
    void solution(vector<vector<int>> board) {
        vector<int> ans(3);
        for(int i = 0; i < board.size();++i){
            for(int j = 0;j < board[0].size();++j){
                int tmp = 0;
                if(board[i][j] == 1){
                    dfs(board, tmp, i, j);
                }
                if(tmp != 0)
                    ans[tmp - 1]++;
            }
        }
        for(int i: ans)
            cout<<i<<" ";
        cout <<"\n";
    }
};

int main() {
    Solution s;
    s.solution({{0,1,1,0,1}, {1,0,1,0,0}, {1,0,0,0,1},{1,0,1,1,0}});
    s.solution({{0,1,0,0,1}, {1,1,0,0,1}, {0,0,0,1,0}});
    s.solution({{1,1,0}, {1,0,1}, {0,1,1}});
    s.solution({{0,0,0}, {0,0,0}, {0,0,0}});
    s.solution({{1,1,1}, {1,1,1}, {1,1,1}});
    return 0;
}