#include <bits/stdc++.h>
int maximumProfit(vector<int> &prices) {
    int profit = 0;
    int first = INT_MAX, second = 0;
    for (int i = 0; i < prices.size(); i++) {
        if (prices[i] < first) {
            first = prices[i];
        }
        profit = prices[i] - first;
        if (second < profit) {
            second = profit;
        }
    }
    return second;
}