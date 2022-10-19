/*
 * @lc app=leetcode id=139 lang=cpp
 *
 * [139] Word Break
 */

// @lc code=start
class Solution
{
public:
    bool wordBreak(string s, vector<string> &wordDict)
    {
        int n = s.size();
        vector<int> dp(n + 1);
        dp[0] = 1;
        unordered_set<string> st;
        for (auto &a : wordDict)
            st.insert(a);
        for (int i = 1; i <= n; ++i)
        {
            for (int j = i - 1; j >= 0; --j)
            {
                string str = s.substr(j, i - j);
                if (dp[j] && st.count(str))
                {
                    dp[i] = 1;
                    break;
                }
            }
        }
        return dp[n];
    }
};
// @lc code=end
