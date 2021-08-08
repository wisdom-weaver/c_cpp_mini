#include <iostream>
#include <stack>
using namespace std;

void insert_at_bottom(stack<int> &st, int n)
{
  if (st.empty())
    return st.push(n);
  int top_elem = st.top();
  st.pop();
  insert_at_bottom(st, n);
  st.push(top_elem);
}

void reverse_stack(stack<int> &st)
{
  if (st.empty())
    return;
  int n = st.top();
  st.pop();
  reverse_stack(st);
  insert_at_bottom(st, n);
}

void display(stack<int> &st)
{
  stack<int> temp = st;
  while (!temp.empty())
  {
    cout << temp.top() << " ";
    temp.pop();
  }
  cout << "TOP\n";
}

int main()
{
  stack<int> st;
  int n = 5;
  while (--n)
    st.push(n);
  display(st);
  reverse_stack(st);
  display(st);
  return 0;
}
