#include<bits/stdc++.h>
bool areAnagram(string &str1, string &str2) {
    if (str1.length() != str2.length()) return false;
    unordered_map<char, int> m;
    for (auto ch : str1) m[ch]++;
    for (auto ch : str2) m[ch]--;
    for (auto val : m) {
        if (val.second != 0) return false;
    }
    return true;
}