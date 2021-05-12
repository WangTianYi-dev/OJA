#include "leetcode.h"

class MedianFinder {
  public:
    /** initialize your data structure here. */
    priority_queue<int> q1;
    priority_queue<int, vector<int>, greater<int>> q2;

    MedianFinder() {
    }

    void addNum(int num) {
        q1.push(num);
        q2.push(q1.top());
        q1.pop();
        if (q1.size() < q2.size()) {
            q1.push(q2.top());
            q2.pop();
        }
    }

    double findMedian() {
        return q1.size() == q2.size() ? (q1.top() + q2.top()) * 0.5 : (double)q1.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */