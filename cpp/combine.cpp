/***
 *Find all possible combinations of k numbers that add up to a number n, 
 given that only numbers from 1 to 9 can be used and each combination should be a unique set of numbers.
 Ensure that numbers within the set are sorted in ascending order.
 Example 1:
Input: k = 3, n = 7
Output:
[[1,2,4]]
Example 2:
Input: k = 3, n = 9
Output:
[[1,2,6], [1,3,5], [2,3,4]]
 */
#include <iostream>
#include <vector>
#include <sstream>
#include <iterator>
using namespace std;
vector<vector<int> > results;
void combine(int begin, vector<int> vec, int k, int n) {
    if (begin > 9 || n <= 0 || k < 1) {
        return;
    }
    if (k == 1) {
        if (begin <= 9 && n <= 9 && n >= begin) {
            vec.push_back(n);
            results.push_back(vec);
            vec.pop_back();
        }
    } else {
        for (int i = begin; i <= 9; ++i) {
            vec.push_back(i);
            combine(i + 1, vec, k - 1, n - i);
            vec.pop_back();
        }
    }
}

vector<vector<int> > combinationSum3(int k, int n) {
    vector<int> vec;
    combine(1, vec, k, n);
    return results;
}

int main(int argc, char** argv) {
    combinationSum3(3, 9);
    ostringstream os;
    vector<vector<int> >::iterator it = results.begin();
    for (; it != results.end(); ++it) {
        os.str("");
        copy(it->begin(), it->end(), ostream_iterator<int>(os, ","));
        cout << os.str() << endl;
    }
}
