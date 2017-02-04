/***************************************************************************
 * 
 * Copyright (c) 2014 Baidu.com, Inc. All Rights Reserved
 * find all the continues numbers which's sum is equal to one number 
 * 
 **************************************************************************/
#include <iostream>
using namespace std;

void print_seq(int start, int end) {
    while (start <= end) {
        cout << start << ",";
        ++start;
    }
    cout << endl;
}

void find_continuous_seq(int sum) {
    if (sum < 3) {
       cout << sum << endl; 
    }
    int small = 1;
    int big = 2;
    int cur_sum = small + big;
    int mid = sum/2;
    while (small <= mid) {
        if (cur_sum == sum) {
            print_seq(small, big);
            ++big;
            cur_sum += big;
        } else if (cur_sum < sum) {
            ++big;
            cur_sum += big;
        } else {
            cur_sum -= small;
            ++small;
        }
    }
}

int main() {
    find_continuous_seq(15);
}





















/* vim: set ts=4 sw=4 sts=4 tw=100 */
