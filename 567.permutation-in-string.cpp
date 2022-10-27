/*
 * @lc app=leetcode id=567 lang=cpp
 *
 * [567] Permutation in String
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool checkInclusion(string s1, string s2)
    {
        int n = s2.size();
        int m = s1.size();
        if (m > n)
            return false;
        vector<int> mp1(128);
        vector<int> mp2(128);
        for (auto a : s1)
            mp1[a]++;
        for (int i = 0; i < n; ++i)
        {
            mp2[s2[i]]++;
            if (i >= m)
                mp2[s2[i - m]]--;
            if (mp1 == mp2)
                return true;
        }
        return false;
    }
};
// @lc code=end
