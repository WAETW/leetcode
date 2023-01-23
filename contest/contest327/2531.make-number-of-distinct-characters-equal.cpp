#include "../../tools/utils.h"

class Solution {
public:
    bool isItPossible(string word1, string word2) {
        vector<int> mp1(26);
        vector<int> mp2(26);
        int c1 = 0, c2 = 0;
        for(auto &a:word1) {
            if(mp1[a - 'a'] == 0)
                ++c1;
            mp1[a - 'a']++;
        }
        for(auto &a:word2) {
            if(mp2[a - 'a'] == 0)
                ++c2;
            mp2[a - 'a']++;
        }
        for(int i = 0;i < 26;++i){
            for(int j = 0;j < 26;++j){
                if(mp1[i] != 0 && mp2[j] != 0){
                    --mp1[i];
                    --mp2[j];
                    if(mp1[i] == 0)
                        --c1;
                    if(mp2[j] == 0)
                        --c2;
                    if(mp1[j] == 0)
                        ++c1;
                    if(mp2[i] == 0)
                        ++c2;
                    ++mp1[j];
                    ++mp2[i];
                    if(c1 == c2)
                        return true;
                    --mp1[j];
                    --mp2[i];
                    if(mp1[j] == 0)
                        --c1;
                    if(mp2[i] == 0)
                        --c2;
                    if(mp1[i] == 0)
                        ++c1;
                    if(mp2[j] == 0)
                        ++c2;
                    ++mp1[i];
                    ++mp2[j];
                }
            }
        }
        return false;
    }
};

int main() {
    Solution s;
    cout << s.isItPossible("ac", "b") <<"\n";
    cout << s.isItPossible("abcc", "aab") <<"\n";
    cout << s.isItPossible("abcde", "fghij") <<"\n";
}