#include <iostream>
using namespace std;
int main()
{
    double d = 0;
    int i = *(int*)(&d);
    cout << i << endl;
}