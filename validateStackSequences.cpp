#include <vector>
#include <stdio.h>
using namespace std;

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        vector<int> temp;
        auto ptpopped = popped.begin();
        for (int i : pushed) {
            temp.push_back(i);
            while (!temp.empty() && temp.back() == *ptpopped) {
                temp.pop_back();
                ptpopped++;
            }
        }
        return ptpopped == popped.end();
    }
};