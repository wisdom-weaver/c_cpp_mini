#include <iostream>
#include <stack>
#include <cmath>
using namespace std;

int prefix_evaluation(string s)
{
  stack<int> st;
  for (int i = s.length() - 1; i >= 0; i--)
  {
    if (s[i] >= '0' && s[i] <= '9')
      st.push(s[i] - '0');
    else
    {
      int op1 = st.top(); st.pop();
      int op2 = st.top(); st.pop();
      int res = 0;
      switch (s[i])
      {
        case '+': res = op1 + op2; break;
        case '-': res = op1 - op2; break;
        case '*': res = op1 * op2; break;
        case '/': res = op1 / op2; break;
        case '^': res = pow(op1,op2); break;
      }
      st.push(res);
    }
  }
  return st.top();
}

int main()
{
  string exp = "-+7*45+20";
  cout << exp << "\n";
  cout << "eval:" << prefix_evaluation(exp) << endl;
  return 0;
}
