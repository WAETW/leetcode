/*
 * @lc app=leetcode id=155 lang=cpp
 *
 * [155] Min Stack
 */

// @lc code=start
class MinStack {
   public:
    stack<int> st;
    stack<int> minist;
    MinStack() {
    }

    void push(int val) {
        st.push(val);
        if (minist.empty() || minist.top() >= val) {
            minist.push(val);
        }
    }

    void pop() {
        if (st.empty())
            return;
        if (st.top() == minist.top()) {
            minist.pop();
        }
        st.pop();
    }

    int top() {
        return st.top();
    }

    int getMin() {
        return minist.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
// @lc code=end
