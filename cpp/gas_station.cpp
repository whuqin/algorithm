/***************************************************************************
 * 
 * Copyright (c) 2014 whuqin. All Rights Reserved
 * There are N gas stations along a circular route, where the amount of gas at station i is gas[i].
 *
 * You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from station i to its next station (i+1). 
 * You begin the journey with an empty tank at one of the gas stations.
 *
 * Return the starting gas station's index if you can travel around the circuit once, otherwise return -1.
 * 
 **************************************************************************/

int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
    int n = gas.size();
    int left = 0;
    int sum = 0;
    int start = 0;
    for (int i = 0; i < n; ++i) {
        left += gas[i] - cost[i];
        sum += gas[i] - cost[i];
        if (left < 0) {
            start = i + 1;
            left = 0;
        }
    }
    return sum >= 0 ? start : -1;
}
/* vim: set ts=4 sw=4 sts=4 tw=100 */
