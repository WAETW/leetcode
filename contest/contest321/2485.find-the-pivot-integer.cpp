class Solution {
   public:
    int pivotInteger(int n) {
        int l = 0;
        int r = 0;
        int pvt = n / 2;
        if (n == 1)
            return 1;
        if (n % 2) {
            r = n;
        }
        for (int i = 0, j = pvt; i <= pvt; ++i, ++j) {
            l += i;
            r += j;
        }
        for (;;) {
            if (l == r)
                break;
            if (l < r) {
                r -= pvt;
                pvt++;
                l += pvt;
            } else if (l > r) {
                pvt = -1;
                break;
            }
        }
        return pvt;
    }
};