#include <bits/stdc++.h>
using namespace std;

bool is_operator(char c)
{
  return c == '+' || c == '-' || c == '*' || c == '/';
}

bool contains_redundant_paranthesis(string s)
{
  stack<char> st;
  for (int i = 0; i < s.length(); i++)
  {
    if (is_operator(s[i]) || s[i] == '(')
      st.push(s[i]);
    else if (s[i] == ')')
    {
      if (st.top() == '(')
        return true;
      while (is_operator(st.top()))
        st.pop();
      st.pop();
    }
  }
  return false;
}

int main()
{
  string s = "((a+b))";
  cout << s << " : " << contains_redundant_paranthesis(s) << endl;
  s="(a+b)";
  cout << s << " : " << contains_redundant_paranthesis(s) << endl;
  return 0;
}
