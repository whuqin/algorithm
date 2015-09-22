/**
 * Given an array of n integers where n > 1, nums, return an array output such that output[i] is equal to the product of all the elements of
 * nums except nums[i].
 * Solve it without division and in O(n).
 * For example, given [1,2,3,4], return [24,12,8,6].
 */
#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

//类似于笛卡尔积
vector<int> productExceptSelf(vector<int>& nums) {
   vector<int> output(nums.size(), 1);
   if (nums.size() == 2) {
       output[0] = nums[1];
       output[1] = nums[0];
       return output;
   }
   //记录i左边数的乘积
   for (int i = 1; i < nums.size(); ++i) {
       output[i] = nums[i - 1] * output[i - 1];
   }
   
   //right记录i右边数的乘积
   int right = 1;
   for (int i = nums.size() - 2; i >= 0; --i) {
       right = right * nums[i + 1];
       //左边数的乘积 * 右边数的乘积
       output[i] = right * output[i];
   }
   
   return output;
}

int main(int argc, char** argv) {
    int arr[] = {9, 0, -2};
    vector<int> vec(arr, arr + 3);
    vector<int> output = productExceptSelf(vec);
    copy(output.begin(), output.end(), ostream_iterator<int>(cout, ","));
}
