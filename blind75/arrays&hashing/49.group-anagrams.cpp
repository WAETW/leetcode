/*
 * @lc app=leetcode id=49 lang=cpp
 *
 * [49] Group Anagrams
 */

// @lc code=start
class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        unordered_map<string, vector<string>> mp;
        for (auto a : strs)
        {
            string tmp = a;
            sort(a.begin(), a.end());
            mp[a].push_back(tmp);
        }
        vector<vector<string>> ans;
        for (auto a : mp)
        {
            ans.push_back(a.second);
        }
        return ans;
    }
};
// @lc code=end
