/*
 * @lc app=leetcode id=128 lang=cpp
 *
 * [128] Longest Consecutive Sequence
 */

// @lc code=start
class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        unordered_set<int> st;
        int ans = 0;
        for (auto a : nums)
        {
            st.insert(a);
        }
        for (auto a : st)
        {
            int curr = 1;
            if (!st.count(a - 1))
            {
                while (st.count(a + curr))
                {
                    ++curr;
                }
                ans = max(ans, curr);
            }
        }
        return ans;
    }
};
// @lc code=end
