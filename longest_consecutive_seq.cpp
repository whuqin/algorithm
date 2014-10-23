/**
Given an unsorted array of integers, find the length of the longest consecutive elements sequence.

For example,
Given [100, 4, 200, 1, 3, 2],
The longest consecutive elements sequence is [1, 2, 3, 4]. Return its length: 4.

Your algorithm should run in O(n) complexity.
compile:g++ longest_consecutive_seq.cpp -std=c++0x
**/
#include <unordered_set>
#include <vector>
#include <iostream>
using namespace std;

unordered_set<int> nums;

int findConsecutive(int num, int one) {
    unordered_set<int>::iterator it = nums.find(num);
    if (it == nums.end()) {
        return 0;
    }
    num += one;
    nums.erase(it);
    return findConsecutive(num, one) + 1;
}

int longestConsecutive(vector<int> &num) {
    //build hashtable
    for (int i = 0; i < num.size(); ++i) {
        nums.insert(num[i]);
    }
    //search
    int max_len = 0;
    for (int i = 0; i < num.size(); ++i) {
        unordered_set<int>::iterator it = nums.find(num[i]);
        if (it != nums.end()) {
            int left_len = findConsecutive(num[i]-1, -1);
            int right_len = findConsecutive(num[i]+1, 1);
            if (left_len + right_len + 1 > max_len) {
                max_len = left_len + right_len + 1;
            }
            nums.erase(it);
        }
    }
    return max_len;
}

int main() {
    vector<int> vec;
    vec.push_back(100);
    vec.push_back(4);
    vec.push_back(200);
    vec.push_back(1);
    vec.push_back(3);
    vec.push_back(2);
    cout << longestConsecutive(vec) << endl;
}
