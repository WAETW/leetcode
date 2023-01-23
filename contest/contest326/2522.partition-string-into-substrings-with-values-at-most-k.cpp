#include "../../tools/utils.h"

class Solution {
public:
    int minimumPartition(string s, int k) {
        int ans = 0;
        stack<long long> st;
        for(int i = 0;i < s.size();++i){
            if(st.empty() && s[i] - '0' <= k){
                st.push(s[i] - '0');
            }
            else if(st.empty() && s[i] - '0' > k){
                return -1;
            }
            else if(!st.empty() && s[i] - '0' <= k){
                long long tmp = st.top() * 10 + s[i] - '0';
                st.pop();
                if(tmp <= k){
                    st.push(tmp);
                }
                else{
                    st.push(s[i] - '0');
                    ++ans;
                }
            }
            else if(!st.empty() && s[i] - '0' > k){
                return -1;
            }
        }
        return ans + 1;
    }
};

int main() {
    Solution s;
    cout << s.minimumPartition("165462", 60) <<"\n";
    cout << s.minimumPartition("238182", 5) <<"\n";
    cout << s.minimumPartition("2995624428278123422153476983795874268215311982758939386251", 128) <<"\n";
}
