#include <iostream>
#include <stack>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;

class node
{
public:
  int data;
  node *next;
  node(int val)
  {
    data = val;
    next = NULL;
  }
};

class queue
{
  node *front;
  node *back;

public:
  queue()
  {
    front = NULL;
    back = NULL;
  }

  void underflow() { cout << "Underflow!!\n"; }
  int underflow_i() { cout << "Underflow!!\n"; return -999;}
  bool empty() { return front == NULL; }

  void push(int x)
  {
    node *new_node = new node(x);
    if (empty())
    {
      front = new_node;
      back = new_node;
      return;
    }
    back->next = new_node;
    back = new_node;
  }

  void pop()
  {
    if (empty())
      return underflow();
    node *to_del = front;
    front = front->next;
    delete to_del;
  }
  int peek(){
    if (empty())
      return underflow_i();
    return front->data;
  }
};

int main()
{
  queue q;
  int a = 4;
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
