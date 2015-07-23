/**
Given an array nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position.

For example,
Given nums = [1,3,-1,-3,5,3,6,7], and k = 3.

Window position                Max
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7
Therefore, return the max sliding window as [3,3,5,5,6,7].

Note: 
You may assume k is always valid, ie: 1 ≤ k ≤ input array's size for non-empty array.
* */
#include <vector>
#include <iostream>
#include <iterator>
#include <deque>
using namespace std;

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    vector<int> maxSliding;
    deque<int> numDownQueue;//记录当前窗口中可能会成为最大数据的索引

    if (nums.empty()) {
        return maxSliding;
    }

    for (int i = 0; i < nums.size(); ++i) {
        //最大数据的索引已经不再窗口内，则删除掉
        if (!numDownQueue.empty() && numDownQueue.front() < i - k + 1) {
            numDownQueue.pop_front();
        }

        //将比nums[i]小的前面数据删除，因为他们不会有机会成为最大数据
        while (!numDownQueue.empty() && nums[i] >= nums[numDownQueue.back()]) {
                numDownQueue.pop_back();
        }
        numDownQueue.push_back(i);
        
        if (i >= k - 1) {
            maxSliding.push_back(nums[numDownQueue.front()]);
        }
    }
    return maxSliding;
}

int main(int argc, char** argv) {
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(3);
    nums.push_back(-1);
    nums.push_back(-3);
    nums.push_back(5);
    nums.push_back(3);
    nums.push_back(6);
    nums.push_back(7);
    vector<int> sliding = maxSlidingWindow(nums, 3);
    copy(sliding.begin(), sliding.end(), ostream_iterator<int>(cout, ","));
}
