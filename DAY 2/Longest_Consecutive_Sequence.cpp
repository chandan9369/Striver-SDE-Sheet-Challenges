#include <bits/stdc++.h>
int lengthOfLongestConsecutiveSequence(vector<int> &nums, int n) {
    if (nums.size() == 0)
        return 0;
    unordered_set<int> h(begin(nums), end(nums));
    int ans = 1;
    for (auto x : h)
    {
        if (h.count(x - 1) == 0)
        {
            int curr = 1;
            while (h.count(x + curr) != 0)
            {
                curr++;
            }
            ans = max(ans, curr);
        }
    }
    return ans;
}