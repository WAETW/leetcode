#include "../../tools/utils.h"

class Solution {
public:
    int distinctPrimeFactors(vector<int> &nums) {
        set<long long> st;
        for(int i:nums)
            helper(st, i);
        return st.size();
    }

    void helper(set<long long> &st, long long num){
        long long i = 2;
        while(num > 1){
            while( num % i == 0 ){
                st.insert(i);
                num /= i;
            }
            ++i;
        }
    }
};

int main() {
    Solution s;
    vector<int> nums1 = {2,4,3,7,10,6};
    vector<int> nums2 = {2,4,8,16};
    vector<int> nums3 = {2,14,19,19,5,13,18,10,15,20};
    cout << s.distinctPrimeFactors(nums1) <<"\n";
    cout << s.distinctPrimeFactors(nums2) <<"\n";
    cout << s.distinctPrimeFactors(nums3) <<"\n";
}