#include <bits/stdc++.h>
int uniqueSubstrings(string s)
{
    int ans = 0, low = 0;
    unordered_set<char> h;
    for (int i = 0; i < s.length(); i++)
    {
        if (h.find(s[i]) != h.end())
        {
            while (s[low] != s[i])
            {
                h.erase(s[low]);
                low++;
            }
            low++;
        }
        else
        {
            h.insert(s[i]);
        }
        int len = h.size();
        if (ans < len)
            ans = len;
    }
    return ans;
}