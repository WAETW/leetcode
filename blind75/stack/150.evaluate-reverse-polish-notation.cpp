/*
 * @lc app=leetcode id=150 lang=cpp
 *
 * [150] Evaluate Reverse Polish Notation
 */

// @lc code=start
class Solution {
   public:
    int evalRPN(vector<string>& tokens) {
        stack<long long int> st;
        for (auto& a : tokens) {
            if (a != "+" && a != "-" && a != "*" && a != "/") {
                st.push((long long int)stoi(a));
                continue;
            }
            long long int num2 = st.top();
            st.pop();
            long long int num1 = st.top();
            st.pop();
            if (a == "+") {
                st.push(num1 + num2);
            }
            if (a == "-") {
                st.push(num1 - num2);
            }
            if (a == "*") {
                st.push(num1 * num2);
            }
            if (a == "/") {
                st.push(num1 / num2);
            }
        }
        return st.top();
    }
};
// @lc code=end
