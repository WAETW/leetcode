/*
 * @lc app=leetcode id=242 lang=cpp
 *
 * [242] Valid Anagram
 */

// @lc code=start
class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        if (s.size() != t.size())
            return false;
        unordered_map<char, int> mp;
        for (auto a : s)
        {
            mp[a]++;
        }
        for (auto a : t)
        {
            if (!mp.count(a))
                return false;
            else
            {
                mp[a]--;
            }
            if (mp[a] < 0)
            {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end
