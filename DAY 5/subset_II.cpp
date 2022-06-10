#include<bits/stdc++.h>
using namespace std;
// ------------------------------------------- Code Start Here ------------------------------------------------------

/*  With using recursion */

class Solution {
public:
    void solve(vector<int>&arr, vector<vector<int>>&ans, int index, vector<int>&curr) {
        if (index == arr.size()) {
            if (find(ans.begin(), ans.end(), curr) == ans.end())
                ans.push_back(curr);
            return;
        }

        // include
        curr.push_back(arr[index]);
        solve(arr, ans, index + 1, curr);

        // backtrack
        curr.pop_back();

        // exclude
        solve(arr, ans, index + 1, curr);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(begin(nums), end(nums));
        vector<int> temp;
        solve(nums, ans, 0, temp);
        return ans;
    }
};

// ---------------------------------------------------------------------------------------------------

/* without using recursion */

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        vector<vector<int>> res = {{}};
        vector<int> curr;
        int size;

        for (auto num : nums) {
            size = res.size();

            for (int i = 0; i < size; i++) {
                curr = res[i];
                curr.push_back(num);
                if (find(res.begin(), res.end(), curr) == res.end())
                    res.push_back(curr);
            }
        }

        return res;
    }
};