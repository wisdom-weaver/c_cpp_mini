#include <iostream>
#include <queue>
using namespace std;

// method 1 - costly push operation
class stack_1
{
  int N;
  queue<int> q1;
  queue<int> q2;

public:
  stack_1() { N = 0; }

  void push(int x)
  {
    q2.push(x);
    while (!q1.empty())
    {
      q2.push(q1.front());
      q1.pop();
    }
    queue<int> temp = q1;
    q1 = q2;
    q2 = temp;
    N++;
  }

  void pop()
  {
    if (N == 0){cout << "Underflow!!";return;}
    N--;
    q1.pop();
  }

  int top() {
    if (N == 0){cout << "Underflow!!";return -999;}
    return q1.front(); 
  }
  int size() { return N; }
};


// method 2 - costly pop operation
class stack_2
{
  int N;
  queue<int> q1;
  queue<int> q2;

public:
  stack_2() { N = 0; }

  void push(int x)
  {
    q1.push(x);
    N++;
  }

  void pop()
  {
    if (q1.empty() || N == 0){cout << "Underflow!!";return ;}
    while(q1.size()!=1){
      q2.push(q1.front());
      q1.pop();
    }
    q1.pop();

    queue<int> temp = q1;
    q1 = q2;
    q2 = temp;
    N--;
  }

  int top() {
    if (q1.empty() || N == 0){cout << "Underflow!!";return -999;}
    
    while(q1.size()!=1){
      q2.push(q1.front());
      q1.pop();
    }

    int ans = q1.front();
    q2.push(ans);
    queue<int> temp = q1;
    q1 = q2;
    q2 = temp;
    return ans;
  }
  int size() { return N; }
};

int main()
{
  // stack_1 st;
  stack_2 st;
  int a = 4;
  int n = a;
  int i = 0;
  while (++i <= a)
    st.push(i);
  
  cout<<"size:"<<st.size()<<endl;

  n = a + 1;
  while (n--){
    cout << st.top() << endl;
    st.pop();
  }
  return 0;
}
