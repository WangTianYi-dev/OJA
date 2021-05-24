#include "leetcode.h"
class Solution {
  public:
    int strStr(string haystack, string needle) {
        int hlen = haystack.length(), nlen = haystack.length();
        vector<int> next(nlen + 1, -1);
        for (int i = 1, j = -1; i < nlen; i++) {
            while (j != -1 && needle[i] != needle[j + 1]) {
                j = next[j];
            }
            if (needle[i] == needle[j + 1]) {
                j++;
            }
            next[i] = j;
        }

        for (int i = 0, j = -1; i < hlen; i++) {
            while (j != -1 && haystack[i] != needle[j + 1]) {
                j = next[j];
            }
            if (haystack[i] == needle[j + 1]) {
                j++;
            }
            if (j == nlen - 1) {
                return i - j;
            }
        }
        return 0;
    }
};

string stringToString(string input) {
    assert(input.length() >= 2);
    string result;
    for (int i = 1; i < input.length() - 1; i++) {
        char currentChar = input[i];
        if (input[i] == '\\') {
            char nextChar = input[i + 1];
            switch (nextChar) {
            case '\"':
                result.push_back('\"');
                break;
            case '/':
                result.push_back('/');
                break;
            case '\\':
                result.push_back('\\');
                break;
            case 'b':
                result.push_back('\b');
                break;
            case 'f':
                result.push_back('\f');
                break;
            case 'r':
                result.push_back('\r');
                break;
            case 'n':
                result.push_back('\n');
                break;
            case 't':
                result.push_back('\t');
                break;
            default:
                break;
            }
            i++;
        } else {
            result.push_back(currentChar);
        }
    }
    return result;
}

int main() {
    string line;
    while (getline(cin, line)) {
        string haystack = stringToString(line);
        getline(cin, line);
        string needle = stringToString(line);

        int ret = Solution().strStr(haystack, needle);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}