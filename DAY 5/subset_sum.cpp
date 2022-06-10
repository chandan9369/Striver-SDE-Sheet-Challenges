#include<bits/stdc++.h>
using namespace std;
// ------------------------------------------- Code Start Here ------------------------------------------------------
void solve(vector<int>&ans, vector<int>&num, int index, int curr) {
    if (index == num.size()) {
        ans.push_back(curr);
        return;
    }

    int sum = curr;
    solve(ans, num, index + 1, sum);
    sum += num[index];
    solve(ans, num, index + 1, sum);
}
vector<int> subsetSum(vector<int> &num)
{
    vector<int> ans;
    solve(ans, num, 0, 0);
    sort(begin(ans), end(ans));
    return ans;
}

// ------------------------------------------- Code Ends Here -------------------------------------------------------
