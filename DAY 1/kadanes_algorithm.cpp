#include <bits/stdc++.h>
long long maxSubarraySum(int nums[], int n)
{
	long long curr_sum = 0;
	long long largest_sum = INT_MIN;
	for (int i = 0; i < n; i++) {
		curr_sum += nums[i];
		if (curr_sum < 0) {
			curr_sum = 0;
		}
		largest_sum = max(largest_sum, curr_sum);
	}
	return largest_sum;
}