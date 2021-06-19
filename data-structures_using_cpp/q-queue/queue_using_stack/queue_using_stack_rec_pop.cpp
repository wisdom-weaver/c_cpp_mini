#include "bits/stdc++.h"
using namespace std;

class queue_s2{
  stack<int> s1;

  public:
    void push(int x){
      s1.push(x);
    }
    int pop(){
      if(s1.empty()){ cout<<"Queue is empty"<<endl; return -1; }

      // get the top element
      int x = s1.top(); s1.pop();
      // base case=> if stack is empty then return the elem x
      if(s1.empty()) return x;
      // recursive case => call pop to get the next elem and so on till base case is hit
      int item = pop();
      // finally push back all the elements into the stack
      s1.push(x);
      return item;

    }
    
    bool empty(){
      return s1.empty();
    }
};

int main(){
  queue_s2 q;
  int i=0, n=5; while(i<n) q.push(++i);
  i=0; 
  do 
    cout<<q.pop()<<endl; 
  while(++i<n+1);
  return 0;
}