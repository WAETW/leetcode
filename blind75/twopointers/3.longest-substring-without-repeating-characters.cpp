/*
 * @lc app=leetcode id=3 lang=cpp
 *
 * [3] Longest Substring Without Repeating Characters
 */

// @lc code=start
class Solution {
   public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0;
        int n = s.size();
        unordered_set<char> st;
        for (int i = 0, j = 0; j < n;) {
            if (!st.count(s[j])) {
                st.insert(s[j]);
                ans = max(ans, j - i + 1);
                ++j;
            } else {
                st.erase(s[i]);
                ++i;
            }
        }
        return ans;
    }
};
// @lc code=end
