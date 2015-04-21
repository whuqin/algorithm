/**
Given a range [m, n] where 0 <= m <= n <= 2147483647, return the bitwise AND of all numbers in this range, inclusive.

For example, given the range [5, 7], you should return 4.
*/
#include <iostream>
using namespace std;

int rangeBitwiseAnd(int m, int n) {
    while (n > m) {
        n = n & (n - 1);
    }
    return n;
}

/**
 * count the number of 1 bit in the binary format of n
 */
int countNumOf1bit(int n) {
    int count = 0;
    while (n > 0) {
        n &= n-1;
        ++count;
    }
    return count;
}

int main() {
    cout << rangeBitwiseAnd(5, 7) << endl;
    cout << rangeBitwiseAnd(0, 2147483647) << endl;
    cout << countNumOf1bit(1) << endl;
    cout << countNumOf1bit(3) << endl;
}
