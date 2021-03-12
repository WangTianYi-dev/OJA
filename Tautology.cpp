#include <cstring>
#include <iostream>
#include <stack>
using namespace std;

// WFF逻辑表达式最大长度
const int MAX_LEN = 101;

// 枚举编码表
// 变量字符p,q,r,s,t取值范围为0(假)、1(真), 排列组合共2^5种可能
// 使用char的低5位分别代表这5个变量，则0x1F（0001 1111）可覆盖这32种可能的变化值
const char ENUM_CODE = 0X1F;

// 逻辑变量掩码值
const char P_MASK = 0x01;
const char Q_MASK = 0x02;
const char R_MASK = 0x04;
const char S_MASK = 0x08;
const char T_MASK = 0x10;

// 逻辑变量名
#define p 'p'
#define q 'q'
#define r 'r'
#define s 's'
#define t 't'

// 逻辑算符名
#define K 'K'
#define A 'A'
#define N 'N'
#define C 'C'
#define E 'E'

// 逻辑运算
// (注意：由于参数不是bit类型, 因此使用的是逻辑运算符而非位运算符)
#define _K(w, x) ((w) && (x)) //	K --> and:  w && x
#define _A(w, x) ((w) || (x)) //	A --> or:  w || x
#define _N(w) (!(w)) //	N --> not :  !w
#define _C(w, x) ((!(w)) || (x)) //	C --> implies :  (!w) || x
#define _E(w, x) ((w) == (x)) //	E --> equals :  w == x

/*  
 * 判断逻辑表达式的运算结果是否为真
 * @param WFF 逻辑表达式
 * @param code 当前的变量值编码表
 * return true:值为真; true:值为假
 */
bool isTrue(char* WFF, char code);

/*  
 * 提取变量字符当前的编码值
 * @param ch 变量字符:p,q,r,s,t
 * @param code 当前的变量值编码表
 * return 0: ch = 0
 *        1: ch = 1 
 *        2: ch不是变量字符
 */
char toVal(char ch, char code);

/*  
 * 取出栈顶元素
 * @param st 栈
 * return 栈顶元素
 */
char getTop(stack<char>* wffStack);

int main(void)
{
    char WFF[MAX_LEN];
    while (cin >> WFF && WFF[0] != '0') {
        bool isTautology = true;

        for (char code = 0; code < ENUM_CODE; code++) {
            isTautology &= isTrue(WFF, code);
            if (isTautology == false) {
                break;
            }
        }
        cout << (isTautology ? "tautology" : "not") << endl;
    }
    return 0;
}

bool isTrue(char* WFF, char code)
{
    stack<char> wffStack;
    const int LEN = strlen(WFF);

    // 从后向前推演表达式的值
    for (int i = LEN - 1; i >= 0; i--) {
        char ch = WFF[i];
        char val = toVal(ch, code);

        // ch是逻辑变量, 直接入栈
        if (val <= 1) {
            wffStack.push(val);

            // ch是逻辑运算符, 从栈中取出元素运算后, 把结果回栈
        } else {

            // 一目运算
            if (N == ch) {
                char w = getTop(&wffStack);
                wffStack.push(_N(w));

                // 二目运算
            } else {
                char w = getTop(&wffStack);
                char x = getTop(&wffStack);

                if (K == ch) {
                    wffStack.push(_K(w, x));

                } else if (A == ch) {
                    wffStack.push(_A(w, x));

                } else if (C == ch) {
                    wffStack.push(_C(w, x));

                } else if (E == ch) {
                    wffStack.push(_E(w, x));
                }
            }
        }
    }

    // 最终栈内只剩下1个元素且值为真
    return (wffStack.size() == 1 && wffStack.top() == 1);
}

char toVal(char ch, char code)
{
    char val = 2;
    switch (ch) {
    case p: {
        val = ((code & P_MASK) == 0 ? 0 : 1);
        break;
    }
    case q: {
        val = ((code & Q_MASK) == 0 ? 0 : 1);
        break;
    }
    case r: {
        val = ((code & R_MASK) == 0 ? 0 : 1);
        break;
    }
    case s: {
        val = ((code & S_MASK) == 0 ? 0 : 1);
        break;
    }
    case t: {
        val = ((code & T_MASK) == 0 ? 0 : 1);
        break;
    }
    default: {
        val = 2;
    }
    }
    return val;
}

char getTop(stack<char>* wffStack)
{
    char e = wffStack->top();
    wffStack->pop();
    return e;
}