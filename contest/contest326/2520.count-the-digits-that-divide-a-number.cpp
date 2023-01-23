#include "../../tools/utils.h"

class Solution {
public:
    int countDigits(int num) {
        int tmp = num;
        int ans = 0;
        vector<int> mp(10);
        while (tmp / 10){
            mp[tmp % 10]++;
            tmp /= 10;
        }
        mp[tmp]++;
        for(int i = 1; i < 10;++i){
            if(mp[i]){
                if(num % i == 0){
                    ans += mp[i];
                }
            }
        }
        return ans;
    }
};

int main() {
    Solution s;
    cout << s.countDigits(7) <<"\n";
    cout << s.countDigits(121) <<"\n";
    cout << s.countDigits(1248) <<"\n";
}