/*
This is subscriber-only problem
*/
/* Problem
Given n nodes labeled from 0 to n - 1 and a list of undirected edges (each edge is a pair of nodes),
write a function to find the number of connected components in an undirected graph.
Example 1:
     0          3
     |          |
     1 --- 2    4
Given n = 5 and edges = [[0, 1], [1, 2], [3, 4]], return 2.

Example 2:
     0           4
     |           |
     1 --- 2 --- 3
Given n = 5 and edges = [[0, 1], [1, 2], [2, 3], [3, 4]], return 1.

Note:
You can assume that no duplicate edges will appear in edges. Since all edges are undirected,
[0, 1] is the same as [1, 0] and thus will not appear together in edges.
*/
#include "bits/stdc++.h"
using namespace std;
class Solution
{
public:
    int countComponents(int n, vector<pair<int, int>> &edges)
    {
        vector<vector<int>> adj(n);
        vector<int> visited(n);
        set<vector<int>> st;
        int ans = 1;
        for (auto &a : edges)
        {
            adj[a.first].push_back(a.second);
            adj[a.second].push_back(a.first);
        }
        for (int i = 0; i < n; ++i)
        {
            queue<int> q;
            if (!visited[i])
            {
                q.push(i);
                visited[i] = 1;
            }
            while (!q.empty())
            {
                int index = q.front();
                q.pop();
                for (auto a : adj[index])
                {
                    if (!visited[a])
                    {
                        q.push(a);
                        visited[a] = 1;
                    }
                }
            }
            st.insert(visited);
        }

        return st.size();
    }
};

int main()
{
    int n = 5;
    vector<pair<int, int>> edges{
        {0, 1}, {1, 2}, {3, 4}};
    // vector<pair<int, int>> edges{
    //     {0, 1}, {1, 2}, {2, 3}, {3, 4}};
    Solution s;
    int ans = s.countComponents(n, edges);
    cout << ans << "\n";
}