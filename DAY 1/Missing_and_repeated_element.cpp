#include <bits/stdc++.h>

pair<int, int> missingAndRepeating(vector<int> &arr, int n)
{
    vector<int> freq(n + 1, 0);
    for (int i = 0; i < n; i++) {
        freq[arr[i]]++;
    }
    pair<int, int> ans;
    for (int i = 1; i <= n; i++) {
        if (freq[i] == 0) {
            ans.first = i;
        }
        if (freq[i] == 2) {
            ans.second = i;
        }
    }
    return ans;
}
