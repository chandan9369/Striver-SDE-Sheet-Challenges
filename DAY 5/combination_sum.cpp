#include<bits/stdc++.h>
using namespace std;
// ------------------------------------------- Code Start Here ------------------------------------------------------
class Solution
{
public:
    void solve(vector<vector<int>> &res, vector<int> &arr, vector<int> &candidates, int sum, int index)
    {
        // base case
        if (sum == 0)
        {
            res.push_back(arr);
            return;
        }
        // recursive case
        for (int i = index; i < candidates.size(); i++)
        {
            if (sum - candidates[i] >= 0)
            {
                arr.push_back(candidates[i]);
                sum -= candidates[i];
                // calling for sub problem
                solve(res, arr, candidates, sum, i);
                // backtrack
                sum += candidates[i];
                arr.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        sort(begin(candidates), end(candidates));
        vector<vector<int>> res;
        vector<int> arr;
        solve(res, arr, candidates, target, 0);
        return res;
    }
};
void solve() {

}


// ------------------------------------------- Code Ends Here -------------------------------------------------------

int main() {

// ------------------------------------------------------------------------------------------------------------------
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

// ------------------------------------------------------------------------------------------------------------------

    int t = 1;
    // cin >> t;
    while (t--) solve();
}