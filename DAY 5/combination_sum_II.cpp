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
			if (i > index and candidates[i] == candidates[i - 1])
			{
				continue;
			}
			int pick = candidates[i];
			// backtracking
			if (sum - pick < 0)
				break;

			arr.push_back(pick);
			solve(res, arr, candidates, sum - pick, i + 1);
			arr.pop_back();
		}
	}
	vector<vector<int>> combinationSum2(vector<int> &candidates, int n, int target)
	{
		sort(begin(candidates), end(candidates));
		vector<vector<int>> res;
		vector<int> arr;
		solve(res, arr, candidates, target, 0);
		return res;
	}
};




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