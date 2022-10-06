/*
 * @lc app=leetcode id=20 lang=cpp
 *
 * [20] Valid Parentheses
 */

// @lc code=start
#include "bits/stdc++.h"
using namespace std;
class Solution {
   public:
    bool isValid(string s) {
        stack<char> st;
        int n = s.size();
        for (int i = 0; i < n; ++i) {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
                st.push(s[i]);
            }
            if (!st.empty()) {
                if (s[i] == ')') {
                    if (st.top() == '(')
                        st.pop();
                    else
                        return false;
                } else if (s[i] == ']') {
                    if (st.top() == '[')
                        st.pop();
                    else
                        return false;
                } else if (s[i] == '}') {
                    if (st.top() == '{')
                        st.pop();
                    else
                        return false;
                }
            } else
                return false;
        }
        if (!st.empty())
            return false;
        return true;
    }
};
// @lc code=end
