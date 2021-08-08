#include <iostream>
using namespace std;
#define N 10

class stack
{
  int *arr;

public:
  int top;
  stack()
  {
    arr = new int[N];
    top = -1;
  }

  void underflow()
  {
    cout << "Stack Underflow" << endl;
    return;
  }
  int underflow_i()
  {
    cout << "Stack Underflow" << endl;
    return -999;
  }

  void overflow()
  {
    cout << "Stack Overflow" << endl;
    return;
  }

  bool empty() { return top == -1; }
  bool full() { return top == N - 1; }

  void push(int x)
  {
    if (this->full())
      return overflow();
    arr[++top] = x;
  }

  void pop()
  {
    if (this->empty())
      return underflow();
    top--;
  }

  int peek()
  {
    if (this->empty())
      return underflow_i();
    return arr[top];
  }
};

int main()
{
  stack st;
  int n = 11;
  while (n--)
    st.push(n);
  n = 11;
  while (n--)
  {
    cout << st.peek() << endl;
    st.pop();
  }

  return 0;
}
