#include<bits/stdc++.h>
using namespace std;
// ------------------------------------------- Code Start Here ------------------------------------------------------
vector<int> solve(int a[], int b[], int n, int m) {
	int i = 0, j = 0;
	vector<int> v;
	while (i < n and j < m) {
		if (a[i] < b[j]) {
			v.push_back(a[i]);
			i++;
		}
		else {
			v.push_back(b[j]);
			j++;
		}
	}
	while (i < n) {
		v.push_back(a[i]);
		i++;
	}
	while (j < m) {
		v.push_back(b[j]);
		j++;
	}
	return v;
}

int ninjaAndLadoos(vector<int> &arr1, vector<int> &arr2, int m, int n, int k) {
	// Write your code here.
	vector<int> res = solve(arr1, arr2, n, m);
	return res[k - 1];
}
