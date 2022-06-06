#include <bits/stdc++.h>
vector<vector<int>> pairSum(vector<int> &nums, int target) {
    // Write your code here.
    vector<vector<int>> ans;
    unordered_map<int, int> h;
    vector<int> res;
    for (auto i = 0; i < nums.size(); i++) {
        if (h.find(target - nums[i]) != h.end()) {
            res.push_back(h[target - nums[i]]);
            res.push_back(i);
            ans.push_back(res);
            res.clear();
        }
        else {
            h.insert({nums[i], i});
        }
    }
    return res;
}
