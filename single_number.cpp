/***************************************************************************
 * 
 * Copyright (c) whuqin. All Rights Reserved
 * Given an array of integers, every element appears three times except for one. Find that single one.
 * Note:
 * Your algorithm should have a linear runtime complexity. 
 * Could you implement it without using extra memory?
 * 
 **************************************************************************/
#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;

//模拟三进制
int singleNumber(int A[], int n) {
    int ones = 0;
    int twos = 0;
    int notthrees = 0;
    for (int i = 0; i < n; ++i) {
        twos |= (ones & A[i]);
        ones ^= A[i];
        notthrees = ~(ones & twos);
        twos &= notthrees;
        ones &= notthrees;
    }
    return ones;
}

int findOnceNum(int A[], int n) {
    //每一位对3的余数是single number的位值
    int numOfDigits = sizeof(int) * 8;
    int digits[numOfDigits];
    //数组初始为0
    //memset(digits, 0, numOfDigits * 4);
    fill_n(digits, numOfDigits, 0);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < numOfDigits; ++j) {
            digits[j] += (A[i] >> j) & 1;
            digits[j] %= 3;
        }
    }
    //二进制转为十进制
    int sum = 0;
    for (int i = 0; i < numOfDigits; ++i) {
        sum += (digits[i] << i);
    }
    return sum; 
}
int main(int argc, char* argv[]) {
    int A[] = {3, 3, 3, 5, 5, 5, 9};
    cout << findOnceNum(A, 7) << endl;
}

/* vim: set ts=4 sw=4 sts=4 tw=100 */
