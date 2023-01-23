//
// Created by WAE on 2022/12/19.
//
#include "../../tools/utils.h"

class Solution{
public:
    int solution(string str){
        int n = str.size();
        int ans = 0;
        for(int i = 0;i < n;++i){
            for(int j = n - 1;j > i;--j){
                string s = str.substr(i, j - i + 1);
                if(helper(s)){
                    ans = max(ans, (int)s.size());
                }
            }
        }
        return ans;
    }
    bool helper(string str){
        vector<int> mp(26);
        for(auto &c: str){
            mp[c - 'a']++;
        }
        for(auto &i:mp){
            if(i % 2 == 1)
                return false;
        }
        return true;
    }
};

int main(){
    Solution s;
    cout<< s.solution("bdaaadadb")<<"\n";
    cout<< s.solution("abacd")<<"\n";
    cout<< s.solution("zthtzh")<<"\n";
}