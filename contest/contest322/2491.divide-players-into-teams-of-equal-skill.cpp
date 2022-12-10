class Solution {
   public:
    long long dividePlayers(vector<int>& skill) {
        int n = skill.size();
        long long ans = 0;
        int prev = 0;
        if (n % 2 != 0)
            return -1;
        priority_queue<int> lq;
        priority_queue<int, vector<int>, greater<int>> hq;
        for (int i : skill) {
            lq.push(i);
            hq.push(i);
        }
        prev = lq.top() + hq.top();
        ans += (lq.top() * hq.top());
        lq.pop();
        hq.pop();
        for (int i = 1; i < n / 2; ++i) {
            int curr = lq.top() + hq.top();
            if (curr != prev)
                return -1;
            ans += (lq.top() * hq.top());
            lq.pop();
            hq.pop();
        }
        return ans;
    }
};