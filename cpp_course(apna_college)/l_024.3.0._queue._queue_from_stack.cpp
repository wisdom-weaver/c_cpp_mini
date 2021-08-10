#include <iostream>
#include <stack>
using namespace std;

// Using 2 stacks
// push - O(1)
// pop - O(n)
class queue_1
{
  stack <int> s1;
  stack <int> s2;
public:
  bool empty(){return (s1.empty() && s2.empty());}
  void push(int x){
    s1.push(x);
  }
  int pop(){
    if(empty()){
      cout<<"Underflow!!\n";
      return -999;
    }
    if(s2.empty()){
      while(!s1.empty()){
        s2.push(s1.top());
        s1.pop();
      }
    }
    int elem = s2.top();
    s2.pop();
    return elem;
  }
};
// Using 1 stack only - Functional call stack- recursion
// push - O(1)
// pop - O(n) - recursive
class queue_2
{
  stack <int> s1;
public:
  bool empty(){return (s1.empty());}
  void push(int x){
    s1.push(x);
  }
  int pop(){
    if(empty()){
      cout<<"Underflow!!\n";
      return -999;
    }
    int elem = s1.top(); s1.pop();
    if(s1.empty()) return elem;

    int item = pop();
    s1.push(elem);
    return item;
  }
};

int main()
{
  // queue_1 q;
  queue_2 q;
  int a = 4;
  int n =a;
  int i=0;
  while(i++<a)
    q.push(i);
  n=a+1;
  while(n--)
    cout<<q.pop()<<endl;
  return 0;
}
