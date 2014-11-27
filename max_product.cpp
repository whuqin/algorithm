/**
Find the contiguous subarray within an array (containing at least one number) which has the largest product.

For example, given the array [2,3,-2,4],
the contiguous subarray [2,3] has the largest product = 6.
**/


#include <iostream>
using namespace std;

int maxProduct(int A[], int n) {
    int ret = A[0], mini = A[0], maxn = A[0];
    for (int i = 1; i < n; ++i) {
        int a = min(mini * A[i], maxn * A[i]);
        int b = max(mini * A[i], maxn * A[i]);
        mini = min(A[i], a);
        maxn = max(A[i], b);
        ret = max(ret, maxn);
    }
    return ret;
}

int main() {
    int A[5] = {-2, 3, 5};    
    int ret = maxProduct(A, 3);
    cout << ret << endl;
    return 0;
}
