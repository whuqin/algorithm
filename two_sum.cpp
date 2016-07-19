/***
 *Given an array of integers, find two numbers such that they add up to a specific target number.
 *The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2.
 *Please note that your returned answers (both index1 and index2) are not zero-based.
 *You may assume that each input would have exactly one solution.
 *Input: numbers={2, 7, 11, 15}, target=9
 *Output: index1=1, index2=2
 */

#include <vector>
#include <map>
#include <iostream>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    map<int, int> num_pair;//key is required number, value is the index: value[index] + key = target
    vector<int> result;
    for (int i = 0; i < nums.size(); ++i) {
        //whether nums[i] is the right operand of one left operand
        map<int, int>::iterator it = num_pair.find(nums[i]);
        if (it != num_pair.end()) {
            result.push_back(it->second + 1);
            result.push_back(i + 1);
            break;
        } else {
            //put the right operand of nums[i]
            num_pair.insert(pair<int, int>(target - nums[i], i));
        }
    }
    return result;
}

int main(int argc, char** argv) {
    vector<int> vec;
    vec.push_back(3);
    vec.push_back(2);
    vec.push_back(4);
    vector<int> res = twoSum(vec, 6);
    for (int i = 0; i < res.size(); ++i) {
        cout << res[i] << endl;
    }
}
