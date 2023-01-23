#include "../../tools/utils.h"

class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        vector<int> prime;
        vector<int> ans = {-1, -1};
        int diff = 1e6;
        for(int i = left;i <= right;++i){
            if(isPrime(i))
                prime.push_back(i);
        }
        if(prime.size() < 2)
            return ans;
        for(int i = 0;i < prime.size() - 1;++i){
            int tmp = prime[i + 1] - prime[i];
            if(diff > tmp){
                diff = tmp;
                ans = {prime[i], prime[i + 1]};
            }
        }
        return ans;
    }

    bool isPrime(int n){
        if (n < 2) {
            return false;
        }
        for (int i = 2; i*i <= n; ++i) {
            if (n % i == 0) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    Solution s;
    printVector(s.closestPrimes(10,19));
    printVector(s.closestPrimes(4,6));
}