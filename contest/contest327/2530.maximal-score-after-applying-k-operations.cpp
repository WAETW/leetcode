#include "../../tools/utils.h"

class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int> pq;
        long long ans = 0;
        for(auto &i : nums)
            pq.push(i);
        while(k--){
            int tmp = pq.top();
            ans += tmp;
            pq.pop();
            int carry = tmp % 3 == 0 ? 0: 1;
            tmp /= 3;
            pq.push(tmp + carry);
        }
        return ans;
    }
};

int main() {
    Solution s;
    vector<int> nums1 = {10,10,10,10,10};
    vector<int> nums2 = {1,10,3,3,3};
    cout << s.maxKelements(nums1, 5) <<"\n";
    cout << s.maxKelements(nums2, 3) <<"\n";
}