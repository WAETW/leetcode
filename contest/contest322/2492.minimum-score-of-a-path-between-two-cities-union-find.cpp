#include "../../tools/utils.h"

class Solution {
   public:
    int minScore(int n, vector<vector<int>> &roads) {
        DSU dsu(n + 1);
        int ans = 1e5;
        for (auto &road : roads) {
            dsu.join(road[0], road[1]);
        }
        dsu.printSet();
        int x = dsu.find(1);
        for(auto &road:roads){
            int u = dsu.find(road[0]);
            int v = dsu.find(road[1]);
            if(u == x || v == x){
                ans = min(ans, road[2]);
            }
        }
        return ans;
    }
};

int main() {
    Solution s;
    vector<vector<int>> roads = {{1, 2, 9}, {2, 3, 6}, {2, 4, 5}, {1, 4, 7}};
    int n = 4;
    int ans = s.minScore(n ,roads);
    cout << ans <<"\n";
}