/***************************************************************************
 * 
 * Copyright (c) whuqin. All Rights Reserved
 * Given an array of integers, every element appears three times except for one. Find that single one.
 * Note:
 * Your algorithm should have a linear runtime complexity. 
 * Could you implement it without using extra memory?
 * 
 **************************************************************************/

int singleNumber(int A[], int n) {
    int ones = 0;
    int twos = 0;
    int notthrees = 0;
    for (int i = 0; i < n; ++i) {
        twos |= (ones & A[i]);
        ones ^= A[i];
        notthrees = ~(ones & twos);
        twos &= notthrees;
        ones &= notthrees;
    }
    return ones;
}
/* vim: set ts=4 sw=4 sts=4 tw=100 */
