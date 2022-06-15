#include<bits/stdc++.h>

void preSmaller(vector<int>&arr, vector<int>&pre, int n) {
  stack<int> st;
  st.push(0);
  pre.push_back(-1);
  for (int i = 1; i < n; i++) {
    while (!st.empty() && arr[st.top()] >= arr[i]) st.pop();
    int pos = st.empty() ? -1 : st.top();
    pre.push_back(pos);
    st.push(i);
  }
}
void nextSmaller(vector<int>&arr, vector<int>&next, int n) {
  stack<int> st;
  next.push_back(arr.size());
  st.push(n - 1);
  for (int i = n - 2; i >= 0; i--) {
    while (!st.empty() && arr[st.top()] >= arr[i]) {
      st.pop();
    }
    int pos = st.empty() ? arr.size() : st.top();
    next.push_back(pos);
    st.push(i);
  }
  reverse(begin(next), end(next));
}
int largestRectangle(vector < int > & arr) {
  // Write your code here.
  vector<int> pre;
  vector<int> next;
  int n = arr.size();
  preSmaller(arr, pre, n);
  nextSmaller(arr, next, n);

  int ans = 0;
  for (int i = 0; i < n; i++) {
    int curr = arr[i];
    curr += (i - pre[i] - 1 ) * arr[i];
    curr += (next[i] - i - 1) * arr[i];
    ans = max(ans, curr);
  }

  return ans;
}