/*
 * @lc app=leetcode id=295 lang=cpp
 *
 * [295] Find Median from Data Stream
 */

// @lc code=start
class MedianFinder {
   public:
    vector<int> v;
    MedianFinder() {
    }
    int pos(vector<int> &v, int t) {
        int l = 0;
        int r = v.size() - 1;
        while (l <= r) {
            int m = l + (r - l) / 2;
            if (v[m] == t)
                return m;
            if (v[m] > t)
                r = m - 1;
            else if (v[m] < t)
                l = m + 1;
        }
        return r + 1;
    }

    void addNum(int num) {
        if (v.empty())
            v.push_back(num);
        else {
            int p = pos(v, num);
            v.insert(v.begin() + p, num);
        }
    }

    double findMedian() {
        int n = v.size();
        if (n % 2 == 1)
            return v[n / 2];
        else
            return (double)(v[n / 2] + v[n / 2 - 1]) / 2;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
// @lc code=end
