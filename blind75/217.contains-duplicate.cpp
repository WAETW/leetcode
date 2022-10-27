/*
 * @lc app=leetcode id=217 lang=cpp
 *
 * [217] Contains Duplicate
 */

// @lc code=start
class Solution
{
public:
    bool containsDuplicate(vector<int> &nums)
    {
        unordered_set<int> st;
        for (auto a : nums)
        {
            if (st.count(a))
                return true;
            st.insert(a);
        }
        return false;
    }
};
// @lc code=end
