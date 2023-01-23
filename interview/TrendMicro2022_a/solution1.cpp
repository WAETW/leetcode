//
// Created by WAE on 2022/12/20.
//
#include "../../tools/utils.h"

class Solution {
public:
    char solution(string str) {
        vector<int> mp(26);
        for(char &c:str){
            mp[c - 'a']++;
        }
        char best_char = 'a';
        int best_res = 0;
        for(int i = 0;i < 26;++i){
            if(mp[i] > best_res){
                best_char = 'a' + i;
                best_res = mp[i];
            }
            else if(mp[i] == best_res){
                continue;
            }
        }
        return best_char;
//        return (max_element(mp.begin(), mp.end()) - mp.begin() + 'a');
    }
};

int main() {
    Solution s;
    cout << s.solution("hello") <<"\n";
    cout << s.solution("helloaa") <<"\n";
    cout << s.solution("helloe") << "\n";
    return 0;
}