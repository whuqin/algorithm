/***************************************************************************
 * 
 * Copyright (c) 2014 Baidu.com, Inc. All Rights Reserved
 * str to int 
 * 
 **************************************************************************/
#include <iostream>
using namespace std;

int str2int(const char* str) {
    if (str == NULL || strlen(str) == 0) {
        return 0;
    }
    
    int sum = 0;
    const char* ptr = str;
    while (*ptr != '\0') {
        int i = *ptr - '0';
        if (i < 0 || i > 9) {
            return 0;
        }
        sum = sum * 10 + i;
        ++ptr;
    }
    return sum; 
}
 
int main() {
    char str[10] = "345";
    cout << str2int(str) << endl;
    return 0;
}





















/* vim: set ts=4 sw=4 sts=4 tw=100 */
