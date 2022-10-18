/*
 * @lc app=leetcode id=5 lang=cpp
 *
 * [5] Longest Palindromic Substring
 */

// @lc code=start
class Solution
{
public:
    string longestPalindrome(string s)
    {
        int maxS = 0;
        int maxL = 1;

        for (int i = 0; i < s.size() - 1; i++)
        {
            // odd
            helper(s, i, i, maxS, maxL);
            // even
            helper(s, i, i + 1, maxS, maxL);
        }
        return s.substr(maxS, maxL);
    }
    void helper(string &s, int l, int r, int &maxS, int &maxL)
    {
        while (l >= 0 && r <= s.size() - 1 && s[l] == s[r])
        {
            l--;
            r++;
        }
        if (r - l - 1 > maxL)
        {
            maxS = l + 1;
            maxL = r - l - 1;
        }
    }
};
// @lc code=end
