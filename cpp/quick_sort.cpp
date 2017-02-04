#include <vector>
#include <iostream>
#include <sstream>
using namespace std;

void sort(int* nums, int begin, int end) {
    if (begin >= end) {
        return;
    }
    cout << "指针:" << sizeof(nums) << endl;
    cout << "int:" << sizeof(int) << endl;
    int len = sizeof(nums) / sizeof(int);
    cout << len << endl;
    return;
    int head = begin;
    int tail = end;
    int pivot = nums[begin];
    while (head < tail) {
        while (nums[head] <= pivot && head < tail) {
            ++head;
        }
        while (nums[tail] >= pivot && head < tail) {
            --tail;
        }

        if (head < tail) {
            int tmp = nums[head];
            nums[head] = nums[tail];
            nums[tail] = tmp;
        }
    }
    if (nums[tail] > pivot) {
        --tail;
    }
    nums[begin] = nums[tail];
    nums[tail] = pivot;
    sort(nums, begin, tail - 1);
    sort(nums, tail + 1, end);
}

int main(void) {
    int nums[] = {7, 5, 3, 4, 10};
    int len = sizeof(nums) / sizeof(int);
    cout << "len:" << len << endl;
    sort(nums, 0, len - 1);
    for (int i = 0; i < len; ++i) {
        //cout << nums[i] << endl;
    }
}
