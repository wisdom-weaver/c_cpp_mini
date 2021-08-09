#include <iostream>
#include <stack>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;

bool is_balanced_paranthesis(string s)
{
  stack<char> st;
  for (int i = 0; i < s.length(); i++)
  {
    if (s[i] == '(' || s[i] == '{' || s[i] == '[')
      st.push(s[i]);
    else if (s[i] == ')' || s[i] == '}' || s[i] == ']') {
      if(st.empty()) return false;
      char top = st.top(); st.pop();
      if(s[i]==')' && top!='(') return false;
      else if(s[i]=='}' && top!='{') return false;
      else if(s[i]==']' && top!='[') return false;
      }
  }
  if(!st.empty()) return false;
  return true;
}

int main()
{
  string s = "(a-b/c)*([a/k]-l)";
  cout << "balanced: " << is_balanced_paranthesis(s) << endl;
  return 0;
}
