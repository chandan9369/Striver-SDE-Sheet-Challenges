#include<bits/stdc++.h>
bool check(char ch, char st) {
    if ((ch == '}' and st == '{') or (ch == ')' and st == '(') or (ch == ']' and st == '[')) return true;
    return false;
}
bool isValidParenthesis(string expression)
{
    // Write your code here.
    string open = "({[";
    stack<char> st;
    for (auto ch : expression) {
        if (!(open.find(ch) == string::npos)) st.push(ch);
        else {
            if (st.empty()) return false;
            if (!check(ch, st.top())) return false;
            st.pop();
        }
    }
    return (st.size() > 0 ? false : true);
}