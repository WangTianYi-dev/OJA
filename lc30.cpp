#include "leetcode.h"

class Solution {
  public:
    unordered_map<string, int> initMap(const vector<string> &words) {
        unordered_map<string, int> m;
        for (const auto &i : words) {
            m[i]++;
        }
        return m;
    }

    unordered_map<string, int> initMap(const string &s, int lo, int hi, int k) {
        unordered_map<string, int> m;
        for (int i = lo; i <= hi - k; i += k) {
            m[s.substr(i, k)]++;
            // cout << s.substr(i, k) << endl;
        }
        return m;
    }

    bool compare(unordered_map<string, int> &m, unordered_map<string, int> &tm,
                 const vector<string> &words) {
        for (auto const i : words) {
            if (tm.find(i) == tm.end() || tm[i] != m[i]) {
                return false;
            }
        }
        return true;
    }

    vector<int> findSubstring(string s, vector<string> &words) {
        int k = words.size();
        int t = words[0].size();
        int l = k * t;
        int lth = s.size();
        if (s.size() < k * t) {
            return vector<int>();
        }
        vector<int> res;
        unordered_map<string, int> m = initMap(words);
        for (auto i : m) {
            cout << i.first << ' ' << i.second << endl;
        }
        for (int i = 0; i < t; i++) {
            int lo = i, hi = k * t + lo;
            auto tm = initMap(s, lo, hi, t);
            for (; hi <= lth;) {
                printf("(lo: %d, hi: %d)\n", lo, hi);
                for (auto i : tm) {
                    cout << i.first << ' ' << i.second << endl;
                }
                if (compare(m, tm, words)) {
                    res.push_back(lo);
                }
                string oldStr = s.substr(lo, t);
                string newStr = s.substr(hi, t);
                tm[oldStr]--;
                tm[newStr]++;
                lo += t, hi += t;
            }
        }
        return res;
    }
};

int main() {
    Solution s;
    string str = "wordgoodgoodgoodbestword";
    vector<string> v = {"word", "good", "best", "good"};
    s.findSubstring(str, v);
}