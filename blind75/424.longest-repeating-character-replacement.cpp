/*
 * @lc app=leetcode id=424 lang=cpp
 *
 * [424] Longest Repeating Character Replacement
 */

// @lc code=start
#include "bits/stdc++.h"
using namespace std;
class Solution {
   public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int ans = 0;
        vector<int> mp(26, 0);
        int maxf = 0;
        for (int l = 0, r = 0; r < n; ++r) {
            mp[s[r] - 'A']++;
            maxf = max(maxf, mp[s[r] - 'A']);
            if (r - maxf - l + 1 > k) {
                mp[s[l] - 'A']--;
                ++l;
            }
            ans = max(ans, r - l + 1);
        }
        return ans;
    }
};
// @lc code=end
