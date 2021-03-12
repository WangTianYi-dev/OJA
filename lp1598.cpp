#include <algorithm>
#include <cctype>
#include <cstdio>
#include <iostream>
#include <map>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

// #define DEBUG

vector<char> letters;
unordered_map<char, int> times;
int height = 0;

void column(int h)
{
    string s = "";
    int l = letters.size();
    for (int i = h; h > 0; h--) {
        // #ifdef DEBUG

        int last = 0;
        s = "";
        if (times['A'] == h) {
            s += "*";
            times['A']--;
        } else {
            s += " ";
        }
        for (int j = 1; j < l; j++) {
            if (times[letters[j]] == h) {
#ifdef DEBUG
                printf("j: %d, last: %d\n", j, last);
                printf("letter: %c, spaceLen: %d, times: %d\n", letters[j], 2 * (j - last) - 1, h);
                // cout << s << endl;
// #else
#endif
                
                s += string(2 * (j - last) - 1, ' ');
                s += "*";
                times[letters[j]]--;
                last = j;
            }
        }
        cout << s << endl;
    }
    s = "";
    for (int i = 0; i < l - 1; i++) {
        s += letters[i];
        s += ' ';
    }
    s += 'Z';
    cout << s << endl;
    // return s;
}

int main()
{
    for (char i = 'A'; i <= 'Z'; i++) {
        letters.push_back(i);
        times[i] = 0;
    }
    char t;
    while (scanf(" %c", &t) != EOF) {
        if (!isalpha(t)) {
            continue;
        } else {
            t = toupper(t);
            times[t]++;
            height = max(times[t], height);
#ifdef DEBUG
            cout << "NEWHEIGHT: " << height << endl;
#endif
        }
    }
#ifdef DEBUG
    printf("FINAL HEIGHT: %d\n", height);
    column(height);
#else
    // cout << column(height);
    column(height);
#endif
    return 0;
}