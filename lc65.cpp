#include <bits/stdc++.h>
using namespace std;

enum State {
    STATE_INITIAL,
    STATE_INT_SIGN,
    STATE_INTEGER,
    STATE_POINT,
    STATE_POINT_WITHOUT_INT,
    STATE_FRACTION,
    STATE_EXP,
    STATE_EXP_SIGN,
    STATE_EXP_NUMBER,
    STATE_END
};

enum CharType {
    CHAR_NUMBER,
    CHAR_EXP,
    CHAR_POINT,
    CHAR_SIGN,
    CHAR_ILLEGAL
};

CharType GetNextCharType(char c) {
    if (c <= '9' && c >= '0') {
        return CHAR_NUMBER;
    } else if (c == 'e' || c == 'E') {
        return CHAR_EXP;
    } else if (c == '.') {
        return CHAR_POINT;
    } else if (c == '+' || c == '-') {
        return CHAR_SIGN;
    } else {
        return CHAR_ILLEGAL;
    }
}

unordered_map<State, unordered_map<CharType, State>> transferMap{
    {STATE_INITIAL,
     {{CHAR_NUMBER, STATE_INTEGER},
      {CHAR_POINT, STATE_POINT_WITHOUT_INT},
      {CHAR_SIGN, STATE_INT_SIGN}}},
    {STATE_INT_SIGN,
     {{CHAR_NUMBER, STATE_INTEGER},
      {CHAR_POINT, STATE_POINT_WITHOUT_INT}}},
    {STATE_POINT,
     {{CHAR_NUMBER, STATE_FRACTION},
      {CHAR_EXP, STATE_EXP}}},
    {STATE_POINT_WITHOUT_INT,
     {{CHAR_NUMBER, STATE_FRACTION}}},
    {STATE_INTEGER,
     {{CHAR_NUMBER, STATE_INTEGER},
      {CHAR_EXP, STATE_EXP},
      {CHAR_POINT, STATE_POINT}}},
    {STATE_FRACTION,
     {{CHAR_NUMBER, STATE_FRACTION},
      {CHAR_EXP, STATE_EXP}}},
    {STATE_EXP,
     {{CHAR_NUMBER, STATE_EXP_NUMBER},
      {CHAR_SIGN, STATE_EXP_SIGN}}},
    {STATE_EXP_SIGN,
     {{CHAR_NUMBER, STATE_EXP_NUMBER}}},
    {STATE_EXP_NUMBER,
     {{CHAR_NUMBER, STATE_EXP_NUMBER}}}};

class Solution {
  public:
    bool isNumber(const string &s) {
        int len = s.length();
        State curState = STATE_INITIAL;
        for (int i = 0; i < len; i++) {
            CharType nextType = GetNextCharType(s[i]);
            if (transferMap[curState].find(nextType) == transferMap[curState].end()) {
                return false;
            } else {
                curState = transferMap[curState][nextType];
            }
        }
        return curState == STATE_INTEGER || curState == STATE_END || curState == STATE_POINT || curState == STATE_FRACTION ||
               curState == STATE_EXP_NUMBER || curState == STATE_END;
    }
};