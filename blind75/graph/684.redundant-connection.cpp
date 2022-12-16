//
// Created by WAE on 2022/12/16.
//
#include "../../tools/utils.h"

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        DSU dsu(n + 1);
        vector<int> ans;
        for(auto &edge:edges){
            int u = dsu.find(edge[0]);
            int v = dsu.find(edge[1]);
            if(u == v){
                ans = {edge[0], edge[1]};
                break;
            }
            else
                dsu.join(edge[0], edge[1]);
        }
        return ans;
    }
};

int main() {
    Solution s;
    vector<vector<int>> edges = {{ 1, 2 }, { 1, 3 }, { 2, 3 }};
//    vector<vector<int>> edges = {{1,2},{2,3},{3,4},{1,4},{1,5}};
    vector<int> ans = s.findRedundantConnection(edges);
    for(int i:ans){
        cout << i <<" ";
    }
//    cout << ans <<"\n";
}