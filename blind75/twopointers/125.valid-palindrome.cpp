/*
 * @lc app=leetcode id=125 lang=cpp
 *
 * [125] Valid Palindrome
 */

// @lc code=start
class Solution {
   public:
    bool isPalindrome(string s) {
        int n = s.size();
        for (int i = 0, j = n - 1; i < j;) {
            if (!isalnum(s[i])) {
                ++i;
            } else if (!isalnum(s[j])) {
                --j;
            } else if (tolower(s[i]) != tolower(s[j])) {
                return false;
            } else {
                ++i;
                --j;
            }
        }
        return true;
    }
};
// @lc code=end
