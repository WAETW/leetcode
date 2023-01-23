//
// Created by WAE on 2022/12/20.
//
#include "../../tools/utils.h"

class Solution {
public:
    int solution(vector<int> arr) {
        unordered_map<int, int> first;
        unordered_map<int, int> last;
        int n = arr.size();
        int ans = -1;
        vector<int> prefix(n+1);
        for(int i = 0;i < n;++i){
            if(first.count(arr[i]) == 0)
                first[arr[i]] = i;
            if(last.count(arr[i]) != 0 && last[arr[i]] < i)
                last[arr[i]] = i;
            else
                last[arr[i]] = i;
        }
        for(int i = 0;i < n;++i){
            prefix[i+1] = prefix[i] + arr[i];
        }
        for(int i : arr){
            int start = first[i];
            int end = last[i];
            if(start != end)
                ans = max(ans, (prefix[end + 1] - prefix[start]));
        }
        return ans;
    }
};

int main() {
    Solution s;
    cout << s.solution({1, 3, 6, 1, 6, 6, 9, 9}) <<"\n";
    cout << s.solution({5, 1, 4, 3}) << "\n";
    cout << s.solution({2, 2, 2, 3, 2, 3}) <<"\n";
    cout << s.solution({1, 3, 6, 1, 6, 6, 9, 9, 9}) << "\n";
    cout << s.solution({5, 1, 2, 1}) << "\n";
    return 0;
}