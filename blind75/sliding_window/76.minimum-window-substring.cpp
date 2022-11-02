/*
 * @lc app=leetcode id=76 lang=cpp
 *
 * [76] Minimum Window Substring
 */

// @lc code=start
class Solution {
   public:
    string minWindow(string s, string t) {
        unordered_map<char, int> mp;
        for (auto a : t)
            mp[a]++;
        int m = t.size();
        int n = s.size();
        int i = 0;
        int j = 0;
        for (; j < n;) {
            if (mp[s[j]] > 0)
                m--;
            mp[s[j]]--;
        }
    }
};
// @lc code=end
