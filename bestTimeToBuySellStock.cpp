/**
 * Say you have an array for which the ith element is the price of a given stock on day i.
 * Design an algorithm to find the maximum profit. You may complete at most two transactions.
 * Note:
 * You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again). 
 */
#include <vector>
#include <algorithm>
#include <iostream>
#include <climits>
using namespace std;

int maxProfit(vector<int>& prices) {
    int profit1 = 0;     //the profit of the first transaction
    int profit2 = 0;     //the last profit after the second transaction, profit2 = profit1 - buy2 + sell2
    int buy1 = INT_MAX;  //the minimum price of the first transaction
    int leftAfterBuy2 = INT_MIN;    //the left money after buy the second stock

    for (int i = 0; i < prices.size(); ++i) {
        buy1 = min(buy1, prices[i]);
        profit1 = max(profit1, prices[i] - buy1);
        leftAfterBuy2 = max(leftAfterBuy2, profit1 - prices[i]);
        profit2 = max(profit2, leftAfterBuy2 + prices[i]);
    }
    return profit2;
}

int main(int argc, char** argv) {
    vector<int> prices;
    prices.push_back(2);
    prices.push_back(1);
    prices.push_back(2);
    prices.push_back(0);
    prices.push_back(1);
    cout << maxProfit(prices) << endl;
    return 0;
}
