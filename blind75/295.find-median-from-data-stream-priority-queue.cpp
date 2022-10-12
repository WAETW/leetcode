/*
 * @lc app=leetcode id=295 lang=cpp
 *
 * [295] Find Median from Data Stream
 */

// @lc code=start
class MedianFinder {
   public:
    priority_queue<int> minpq;
    priority_queue<int, vector<int>, greater<int>> maxpq;
    MedianFinder() {
    }

    void addNum(int num) {
        if (minpq.empty()) {
            minpq.push(num);
            return;
        }
        if (minpq.size() > maxpq.size()) {
            if (minpq.top() > num) {
                maxpq.push(minpq.top());
                minpq.pop();
                minpq.push(num);
            } else {
                maxpq.push(num);
            }
        } else {
            if (maxpq.top() < num) {
                minpq.push(maxpq.top());
                maxpq.pop();
                maxpq.push(num);
            } else {
                minpq.push(num);
            }
        }
    }

    double findMedian() {
        if (maxpq.size() == minpq.size())
            return (double)(maxpq.top() + minpq.top()) / 2;
        if (maxpq.size() > minpq.size())
            return (double)maxpq.top();
        else
            return (double)minpq.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
// @lc code=end
