/*
 * @lc app=leetcode id=4 lang=cpp
 *
 * [4] Median of Two Sorted Arrays
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
   public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        for (int i : nums2) {
            int l = 0;
            int r = nums1.size();
            while (l < r) {
                int m = l + (r - l) / 2;
                if (nums1[m] < i) {
                    l = m + 1;
                } else if (nums1[m] > i) {
                    r = m;
                } else if (nums1[m] == i) {
                    r = m;
                    break;
                }
            }
            nums1.insert(nums1.begin() + r, i);
        }
        int n = nums1.size();
        double ans = 0;
        if (n % 2 == 0) {
            ans = ((double)nums1[n / 2] + (double)nums1[n / 2 - 1]) / 2;
        } else {
            ans = nums1[n / 2];
        }
        return ans;
    }
};
// @lc code=end
