#include <stdio.h>
#include <iostream>
using namespace std;
struct s
{
    static int i;
    s() {
        i++;
    }
} a[1000];
int s::i = 0;

int main()
{
    cout << s::i << endl;
    return 0;
}