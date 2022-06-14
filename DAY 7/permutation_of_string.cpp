void solve(vector<string> &ans, string s, int index) {
    if (index == s.length()) {
        ans.push_back(s);
        return;
    }
    for (int i = index; i < s.length(); i++) {
        swap(s[i], s[index]);
        solve(ans, s, index + 1);
        swap(s[i], s[index]);
    }
}
vector<string> findPermutations(string &s) {
    vector<string> ans;
    solve(ans, s, 0);
    return ans;
}