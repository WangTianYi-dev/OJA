// #include <cstdio>
// #include <cstdlib>
// #include <cstring>
// #include <iostream>
// using namespace std;
// char s[1000], tmp[2][1000], ans[1000];
// typedef enum Type {
//     integer,
//     decimal,
//     fraction,
//     percentage,
// } Type;

// void getrev(char* dest, int n, char* s)
// {
//     while (n >= 0 && s[n-1] == '0') {
//         n--;
//     }
//     int i;
//     for (i = 0; i < n; i++) {
//         dest[i] = s[n - i - 1];
//     }
//     dest[i] = 0;
// }

// void parse(Type t, int p)
// {
//     size_t l = strlen(s);
//     switch (t) {
//     case integer:
//     getrev(ans, p, s);
//     break;
//     case decimal:
//     getrev(ans, p, s);
//     }
//     }

//     int main()
//     {
//         Type t = integer;
//         cin >> s;
//         size_t l = strlen(s);
//         int pos;
//         for (pos = 0; pos < l; pos++) {
//             if (s[pos] == '.') {
//                 t = decimal;
//                 break;
//             }
//             if (s[pos] == '/') {
//                 t = fraction;
//                 break;
//             }
//             if (s[pos] == '%') {
//                 t = percentage;
//                 break;
//             }
//         }
//         cout << ans << endl;
//         return 0;
//     }
