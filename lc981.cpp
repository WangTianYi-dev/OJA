#include <bits/stdc++.h>
using namespace std;
class TimeMap {
  public:
    /** Initialize your data structure here. */
    TimeMap() {
    }
    unordered_map<string, vector<pair<int, string>>> m;
    void set(string key, string value, int timestamp) {
        m[key].push_back(pair<int, string>{timestamp, value});
    }

    string get(string key, int timestamp) {
        vector<pair<int, string>> &v = m[key];
        auto i = upper_bound(v.begin(), v.end(), pair<int, string>{timestamp, string({127})});
        if (i != v.begin()) {
            return (i - 1)->second;
        }
        return "";
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */