/*
 * @lc app=leetcode id=76 lang=cpp
 *
 * [76] Minimum Window Substring
 */

// @lc code=start
#include "bits/stdc++.h"
using namespace std;
class Solution {
   public:
    string minWindow(string s, string t) {
        unordered_map<char, int> mp;
        for (char c : t) {
            ++mp[c];
        }
        int maxln = 1e5;
        int count = t.size();
        int m = s.size();
        for (int l = 0, r = 0; r < m;) {
            if (mp.count(s[r])) {
                --count;
            }
        }
    }
};
// @lc code=end
