#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <stack>
#include <vector>
using namespace std;

char line[110];
const char ENUM_CHAR = 0b11111;
const char P_MASK = 0b1;
const char Q_MASK = 0b10;
const char R_MASK = 0b100;
const char S_MASK = 0b1000;
const char T_MASK = 0b10000;
const char p = 'p', q = 'q', r = 'r', s = 's', t = 't',
           K = 'K', A = 'A', N = 'N', C = 'C', E = 'E';

#define _K(w, x) ((w) && (x)) //	K --> and:  w && x
#define _A(w, x) ((w) || (x)) //	A --> or:  w || x
#define _N(w) (!(w)) //	N --> not :  !w
#define _C(w, x) ((!(w)) || (x)) //	C --> implies :  (!w) || x
#define _E(w, x) ((w) == (x)) //	E --> equals :  w == x

char getVal(char ch, char state)
{
    char val;
    switch (ch) {
    case p:
        val = (state & P_MASK) ? 1 : 0;
        break;
    case q:
        val = (state & Q_MASK) ? 1 : 0;
        break;
    case r:
        val = (state & R_MASK) ? 1 : 0;
        break;
    case s:
        val = (state & S_MASK) ? 1 : 0;
        break;
    case t:
        val = (state & T_MASK) ? 1 : 0;
        break;
    default:
        val = 2;
    }
    return val;
}

bool isTrue(char* WFF, char state)
{
    stack<char> wffstack;
    int len = strlen(WFF);
    char ch, val;
    for (int i = len - 1; i >= 0; i--) {
        ch = WFF[i];
        val = getVal(ch, state);
        if (val <= 1) {
            wffstack.push(val);
        } else {
            char w, x;
            if (ch == N) {
                w = wffstack.top();
                wffstack.pop();
                wffstack.push(_N(w));
            } else {
                w = wffstack.top();
                wffstack.pop();
                x = wffstack.top();
                wffstack.pop();
                switch (ch) {
                case K /* constant-expression */:
                    /* code */
                    wffstack.push(_K(w, x));
                    break;
                case A:
                    wffstack.push(_A(w, x));
                    break;
                case C:
                    wffstack.push(_C(w, x));
                    break;
                case E:
                    wffstack.push(_E(w, x));
                    break;
                default:
                    break;
                }
            }
        }
    }
    return wffstack.size() == 1 && wffstack.top() == 1;
}

int main()
{
    while (scanf("%s", line)) {
        if (line[0] == '0')
            break;
        bool tautology = true;
        for (char i = 0; i < ENUM_CHAR; i++) {
            tautology &= isTrue(line, i);
            if (!tautology)
                break;
        }
        // char t[10] = (tautology ? "tautology" : "not");
        if (tautology) {
            puts("tautology");
        } else {
            puts("not");
        }
    }
}
