#include <iostream>
#include <queue>
using namespace std;
long long ones[] = { 1, 11, 111, 1111, 11111, 111111, 1111111, 11111111, 111111111, 1111111111, 11111111111, 111111111111, 1111111111111, 11111111111111, 111111111111111, 1111111111111111, 11111111111111111, 111111111111111111, 1111111111111111111 };
int main()
{
    int l = (sizeof(ones) / sizeof(long long));
    long long ll;
    while (1) {
        cin >> ll;
        if (ll == 0)
            return 0;
        for (int i = 1; i < l; i++) {
            long long rem = ones[i] % ll;
            for (int j = 0; j < i; j++) {
                long long altrem = ones[j] % ll;
                if (altrem == rem) {
                    // cout << "FOR: " << ll << endl; 
                    // cout << ones[i] << endl;
                    // cout << ones[j] << endl;
                    cout << (ones[i] - ones[j]) << '\n';
                    // cout << endl;
                    goto end;
                }
            }
        }
    end:
        ++ll;
    }
}
