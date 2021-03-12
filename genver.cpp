#include <iostream>
#include <time.h>
#include <fstream>
using namespace std;
int main()
{
    long long l;
    scanf("%lld",&l);
    fstream f;
    f.open("t.txt");
    for (long long i = 0; i < l; i++) {
        f << "1";
    }
    f << endl;
    f.close();
    return 0;
}