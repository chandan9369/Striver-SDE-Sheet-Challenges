#include<bits/stdc++.h>
string longestPalinSubstring(string s)
{
    int n = s.length();
    vector<vector<bool>> dp(n, vector<bool>(n, false));
    string ans = "";
    ans += s[0];
    for (int i = 0; i < n; i++) dp[i][i] = true;

    for (int i = n - 1; i >= 0; i--) {
        for (int j = i + 1; j < n; j++) {

            if (s[i] != s[j]) continue;

            // check if the substring has more than or equal to 2 character
            // or not if yes then check previous solutions
            if (j - i == 1 || dp[i + 1][j - 1]) {
                // make this substring as palindrome
                dp[i][j] = true;

                if (ans.size() <= j - i + 1) {
                    // update the answer
                    ans = s.substr(i, j - i + 1);
                }
            }
        }
    }
    return ans;
}