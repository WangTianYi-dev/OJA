#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<vector<string>> displayTable(vector<vector<string>> &orders) {
        map<int, map<string, int>> tables;
        set<string> dishes;
        int n = orders.size();
        for (int i = 0; i < n; i++) {
            int table = atoi(orders[i][1].c_str());
            string dish = orders[i][2];
            tables[table][dish]++;
            if (dishes.count(dish) == 0) {
                dishes.insert(dish);
            }
        }
        vector<vector<string>> res;
        res.push_back(vector<string>());
        res[0].push_back("Table");
        for (auto i = dishes.begin(); i != dishes.end(); i++) {
            res[0].push_back(*i);
        }
        for (auto i = tables.begin(); i != tables.end(); i++) {
            vector<string> v;
            v.push_back(to_string((*i).first));
            map<string, int> &order = (*i).second;
            for (auto i = dishes.begin(); i != dishes.end(); i++) {
                if (order.count(*i) == 0) {
                    v.push_back("0");
                } else {
                    v.push_back(to_string(order[*i]));
                }
            }
            res.push_back(v);
        }
        return res;
    }
};