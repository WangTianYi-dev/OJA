#include <cmath>
#include <iostream>
using namespace std;
double pi = 3.1415926;
int main()
{
    int k, count = 1;
    double s, x, y;
    cin >> k;
    while (k--) {
        cin >> x >> y;
        s = (pi / 2) * (x * x + y * y);
        cout << "Property " << count++ << ": This property will begin eroding in year " << (int)(s / (double)50 + 1) << "." << endl;
    }
    cout << "END OF OUTPUT." << endl;
    return 0;
}
