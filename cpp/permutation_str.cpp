/***************************************************************************
 * 
 * Copyright (c) 2014 Baidu.com, Inc. All Rights Reserved
 * $Id$ 
 * 
 **************************************************************************/
 
#include <iostream>
#include <algorithm>
using namespace std;

void permutation(char* str, char* begin) {
    if (*begin == '\0') {
        cout << str << endl;
    } else {
        char* ch = begin;
        while (*ch != '\0') {
            swap(*begin, *ch);
            permutation(str, begin + 1);
            swap(*begin, *ch);
            ++ch;
        }
    }
}



int main() {
   char str[10] = "abcd"; 
   permutation(str, str);
}




















/* vim: set ts=4 sw=4 sts=4 tw=100 */
