/**
 *Wildcard Matching
 Implement wildcard pattern matching with support for '?' and '*'.
 '?' Matches any single character.
 '*' Matches any sequence of characters (including the empty sequence).
 The matching should cover the entire input string (not partial).
 The function prototype should be:
 bool isMatch(const char *s, const char *p)
 Some examples:
 isMatch("aa","a") false
 isMatch("ab", "?*") true 
 **/

#include <iostream>
using namespace std;
bool isMatch(const char *s, const char *p) {
    if (*p == '\0') {
        return *p == *s;
    }

    if (*p == '*') {
        //*match any seq of char, so jump from begin to end
        while (*s != '\0') {
            if (isMatch(s, p + 1)) {
                return true;
            }
            ++s;
        }
        return isMatch(s, p + 1);
    } else if (*p == *s || *p == '?') {
        return isMatch(s + 1, p + 1);
    } else {
        return false;
    }
}

int main(int argc, char** argv) {
    cout << "isMatch(\"\", \"*\"): " << isMatch("", "*") << endl;
    cout << "isMatch(\"a\", \"*b\"): " << isMatch("a", "*b") << endl;
    cout << "isMatch(\"aa\",\"a\"): " << isMatch("aa","a") << endl;
    cout << "isMatch(\"ab\", \"?*\"): " << isMatch("ab", "?*") << endl;
    cout << "isMatch(\"aa\", \"*\"): " << isMatch("aa", "*") << endl;
    cout << "isMatch(\"aab\", \"c*a*b\"): " << isMatch("aab", "c*a*b") << endl;
}
