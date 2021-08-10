#include <iostream>
using namespace std;

#define N 10

class queue
{
  int *arr;
  int front;
  int back;

public:
  queue()
  {
    arr = new int[N];
    front = -1;
    back = -1;
  }
  void overflow() { cout << "Queue Overflow!!\n"; }
  void underflow() { cout << "Queue Underflow!!\n"; }
  int underflow_i() { cout << "Queue Underflow!!\n"; return -999;}
  bool empty() { return (front == -1 || front>back); }
  
  void push(int x)
  {
    if (back == N - 1)
      return overflow();
    if (front == -1)
      front++;
    arr[++back] = x;
  }
  
  void pop()
  {
    if (empty())
      return underflow();
    front++;
  }
  
  int peek() {
    if (empty())
      return underflow_i();
    return arr[front];
  }
};

int main()
{
  queue q;
  int a = N+1;
  int n =a;
  int i=0;
  while(i++<a)
    q.push(i);
  n=a;
  while(n--){
    cout<<q.peek()<<endl;
    q.pop();
  }
  return 0;
}
