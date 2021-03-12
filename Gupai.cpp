#include <iostream>
using namespace std;
int main()
{
    int n;
    while (cin >> n) {
        long long a = 1, b = 2;
        if (n == 1) {
            cout << a << endl;
        } else if (n == 2) {
            cout << b << endl;
        } else {
            n -= 2;
            long long c;
            while (n--) {
                c = a + b;
                a = b;
                b = c;
            }
            cout << c << endl;
        }
    }
    return 0;
}

// //递归解法，但不是递归写法
// #include<iostream>
// using namespace std;

// int main()
// {
//     int n;
//     long long fx,fy,fz;
//     while(cin>>n)
//     {
//         fx=1;fy=2;
//         if(n==1)
//         cout<<fx<<endl;
//         else if(n==2)
//         cout<<fy<<endl;
//         else
//         {
//             n-=2;
//             while(n--)
//             {
//                 fz=fy+fx;
//                 fx=fy;
//                 fy=fz;
//             }
//             cout<<fz<<endl;
//         }
//     }
// }