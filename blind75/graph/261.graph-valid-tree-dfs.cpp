/*
This is subscriber-only problem
*/
/* Problem
Given n nodes labeled from 0 to n-1 and a list of undirected edges (each edge is a pair of nodes), write a function to check whether these edges make up a valid tree.

Example 1:

n = 5
edges = [[0,1], [0,2], [0,3], [1,4]]
Example 2:

n = 5,
edges = [[0,1], [1,2], [2,3], [1,3], [1,4]]
*/
#include "bits/stdc++.h"
using namespace std;
class Solution {
   public:
    bool validTree(int n, vector<pair<int, int>> &edges) {
        vector<vector<int>> adj(n);
        vector<int> visited(n);
        for (auto &a : edges) {
            adj[a.first].push_back(a.second);
            adj[a.second].push_back(a.first);
        }
        if (!dfs(0, -1, adj, visited))
            return false;
        for (auto a : visited) {
            if (!a)
                return false;
        }
        return true;
    }
    bool dfs(int i, int p, vector<vector<int>> &adj, vector<int> &visited) {
        if (visited[i] == 1)
            return false;
        visited[i] = 1;
        for (int j = 0; j < adj[i].size(); ++j) {
            if (adj[i][j] != p)
                if (!dfs(adj[i][j], i, adj, visited))
                    return false;
        }
        return true;
    }
};

int main() {
    int n = 5;
    vector<pair<int, int>> edges{{0, 1}, {0, 2}, {0, 3}, {1, 4}};
    vector<pair<int, int>> edges1{{0, 1}, {1, 2}, {2, 3}, {1, 3}, {1, 4}};
    Solution s;
    cout << s.validTree(n, edges) << "\n";
    cout << s.validTree(n, edges1) << "\n";
}