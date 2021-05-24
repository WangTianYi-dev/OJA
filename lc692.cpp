#include "leetcode.h"

class Solution {
    struct node {
        int i;
        string s;
        friend bool operator<(const node &a, const node &b) {
            return a.i < b.i;
        }
    };

  public:
    vector<string> topKFrequent(vector<string> &words, int k) {

        unordered_map<string, int> m;
        for (auto i : words) {
            m[i]++;
        }
        priority_queue<node> pq;
        for (auto i : m) {
            pq.push({i.second, i.first});
        }
        vector<string> res;
        for (int i = 0; i < k; i++) {
            res.push_back(pq.top().s);
            pq.pop();
        }
        return res;
    }
};

int main() {
    Solution s;
}