/*
 * @lc app=leetcode id=647 lang=cpp
 *
 * [647] Palindromic Substrings
 */

// @lc code=start
class Solution {
   public:
    int countSubstrings(string s) {
        int n = s.size();
        int ans = 0;
        vector<vector<int>> dp(n, vector<int>(n));
        for (int i = 0; i < n; ++i) {
            dp[i][i] = 1;
        }
        for (int i = n - 1; i >= 0; --i) {
            for (int j = i; j < n; ++j) {
                if (i == j) {
                    ++ans;
                    continue;
                } else {
                    if (i == j - 1) {
                        if (s[i] == s[j]) {
                            dp[i][j] = 1;
                            ++ans;
                        }
                    } else {
                        if (dp[i + 1][j - 1] && s[i] == s[j]) {
                            dp[i][j] = 1;
                            ++ans;
                        }
                    }
                }
            }
        }
        return ans;
    }
};
// @lc code=end
