/**
 * Implement regular expression matching with support for '.' and '*'
 * '.' Matches any single character
 * '*' Matches zero or more of the preceding element
 * */
#include <iostream>
using namespace std;

bool isMatch(const char* s, const char* p) {
    if (*s == '\0' && *p == '\0') {
        return true;
    }
    
    //match current char
    if (*(p + 1) != '*') {
        if (*s == *p || (*p == '.' && *s != '\0')) {
            return isMatch(s + 1, p + 1);
        } else {
            return false;
        } 
    }
    
    while (*s == *p || (*p == '.' && *s != '\0')) {
        //跳过*,尝试匹配
        if (isMatch(s, p + 2)) {
            return true;
        }
        //出现次数加1，尝试匹配
        ++s;
    }
    return isMatch(s, p + 2);
}

int main(int argc, char** argv) {
    char s[] = "abbc";
    char p[] = "ab*bbc";
    if (isMatch(s, p)) {
        cout << s << " -> " << p << " matched" << endl;
    } else {
        cout << s << " -> " << p << " not matched" << endl;
    }
}
