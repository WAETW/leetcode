/*
 * @lc app=leetcode id=347 lang=cpp
 *
 * [347] Top K Frequent Elements
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        unordered_map<int, int> mp;
        vector<int> ans;
        for (auto a : nums)
        {
            mp[a]++;
        }
        priority_queue<pair<int, int>> pq;
        for (auto a : mp)
        {
            pq.push(make_pair(a.second, a.first));
        }
        for (int i = 0; i < k; ++i)
        {
            auto tmp = pq.top();
            pq.pop();
            ans.push_back(tmp.second);
        }
        return ans;
    }
};
// @lc code=end
