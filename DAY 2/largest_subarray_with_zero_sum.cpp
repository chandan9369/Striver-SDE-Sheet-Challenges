#include <bits/stdc++.h>
int LongestSubsetWithZeroSum(vector < int > arr) {

    int n = arr.size();
    unordered_map<int, int> h;
    int preSum = 0;
    int res = 0;
    for (int i = 0; i < n; i++) {
        preSum += arr[i];
        if (preSum == 0) {
            res = i + 1;
        }
        if (h.find(preSum) != h.end()) {
            res = max(res, i - h[preSum]);
        }
        else {
            h.insert({preSum, i});
        }
    }
    return res;

}