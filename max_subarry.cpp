/***************************************************************************
 * 
 * Copyright (c) 2014 Baidu.com, Inc. All Rights Reserved
 * find the subsequence array in which all of items sum is maximum 
 * 
 **************************************************************************/
#include <iostream>
using namespace std;

int max_sum_sub_array(int* arr, int len) {
    if (NULL == arr || len <= 0) {
        return 0x80000000;
    }
    int max_sum = 0x80000000;
    int cur_sum = 0;
    if (int i = 0; i < len; ++i) {
        if (cur_sum <= 0) {
            cur_sum = arr[i];
        } else {
            cur_sum += arr[i];
        }
        if (cur_sum > max_sum) {
            max_sum = cur_sum;
        }
    }
    return max_sum;
}
 
int main() {
    int arr[8] = {-2,1,3,10,-4,7,2,-5};
    cout << max_sum_sub_array(arr, 8) << endl;
}
 





















/* vim: set ts=4 sw=4 sts=4 tw=100 */
