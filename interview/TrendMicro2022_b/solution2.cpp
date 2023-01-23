//
// Created by WAE on 2022/12/18.
//
#include "../../tools/utils.h"

class Solution {
public:
    int solution(vector<vector<int>> A) {
        int ans = 0;
        unordered_map<int, int> mp;
        for (auto &a: A) {
            set<int> st;
            for (int &i: a) {
                st.insert(i);
            }
            for (const auto i: st) {
                mp[i]++;
            }
        }
        for (auto a: mp) {
            if (a.second > 1)
                ans++;
        }
        return ans;
    }
};

int main() {
    Solution s;
    cout << s.solution({{1, 2, 2},
                        {3, 1, 4}}) <<"\n";
    cout << s.solution({{1, 1, 5, 2, 3},
                        {4, 5, 6, 4, 3},
                        {9, 4, 4, 1, 5}}) <<"\n";
    cout << s.solution({{4, 3},
                        {5, 5},
                        {6, 2}}) << "\n";
    return 0;
}