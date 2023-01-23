//
// Created by WAE on 2022/12/18.
//
#include "../../tools/utils.h"

class Solution {
public:
    int solution(int A, int B) {
        int len = (A + B)/4;
        int ans = 0;
        for(int i = len;i > 0;--i){
            int pos = A/i + B/i;
            if(pos >= 4){
                ans = i;
                break;
            }
        }
        return ans;
    }
};

int main() {
    Solution s;
    cout << s.solution(10, 21) <<"\n";
    cout << s.solution(13, 11) <<"\n";
    cout << s.solution(2, 1) << "\n";
    cout << s.solution(1, 8) << "\n";
    return 0;
}