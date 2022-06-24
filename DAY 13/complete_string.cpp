#include<bits/stdc++.h>
static bool cmp(string a, string b) {
    if (a.length() == b.length()) return a < b;
    return a.length() < b.length();
}
string completeString(int n, vector<string> &a) {
    // Write your code here.
    sort(begin(a), end(a), cmp);
    string ans = "";
    unordered_set<string> h(begin(a), end(a));

    for (int i = n - 1; i >= 0; i--) {
        string prefix = "";
        bool make = true;
        for (auto ch : a[i]) {
            prefix += ch;
            if (h.count(prefix) == 0) {
                make = false;
                break;
            }
        }
        if (make && (ans.size() <= a[i].size())) {
            ans = a[i];
        }
    }
    return ans == "" ? "None" : ans;
}