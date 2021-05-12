#include <unordered_map>
#include <iostream>
using namespace std;
int main()
{
    unordered_map<int, int> m;
    int a[] {1,23,4,5,67,8,2,3,5,4,543,2};
    for (auto i : a) {
        m[i]++;
    }
    for (auto i : a) {
        cout << m[i] << endl;
    }
    return 0;
}