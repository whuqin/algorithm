/***************************************************************************
 * 
 * Copyright (c) 2014 Baidu.com, Inc. All Rights Reserved
 * find the two numbers which occurs only once in the array
 * 
 **************************************************************************/
#include <iostream>
using namespace std;

void find_nums_once(int* arr, int len, int* num1, int* num2) {
    if (arr == NULL || len <= 2) {
        return;
    }
    
    int xor_nums = 0;
    for (int i = 0; i < len; ++i) {
        xor_nums ^= arr[i];
    }
    if (xor_nums == 0) {
        return;
    }
    
    //find index of the first bit 1
    int indexofbit1 = 0;
    while ((xor_nums & 1) == 0) {
        xor_nums = xor_nums >> 1;
        ++indexofbit1;
    }
    cout << "after xor" << endl;
    //split the array
    int mask_num = 1 << indexofbit1;
    *num1 = 0;
    *num2 = 0;
    for (int i = 0; i < len; ++i) {
        if ((arr[i] & mask_num) != 0) {
            *num1 ^= arr[i];
        } else {
            *num2 ^= arr[i];
        }
    }
    return;
}

int main() {
    int arr[8] = {2, 4, 3, 6, 3, 2, 5, 5};
    int num1 = 0;
    int num2 = 0;
    find_nums_once(arr, 8, &num1, &num2);
    cout << num1 << "," << num2 << endl;
}

















/* vim: set ts=4 sw=4 sts=4 tw=100 */
