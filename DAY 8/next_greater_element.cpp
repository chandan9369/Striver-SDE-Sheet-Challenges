#include<bits/stdc++.h>
vector<int> nextGreater(vector<int> &arr, int n) {
    // Write your code here
    vector<int> ans;
    stack<int> st;
    ans.push_back(-1);
    st.push(arr[n - 1]);
    for (int i = n - 2; i >= 0; i--) {
        while (!st.empty() && st.top() <= arr[i]) {
            st.pop();
        }
        int val = st.empty() ? -1 : st.top();
        ans.push_back(val);
        st.push(arr[i]);
    }
    reverse(begin(ans), end(ans));
    return ans;
}

