#include "bits/stdc++.h"
using namespace std;

class queue_s2{
  stack<int> s1;
  stack<int> s2;

  public:
    void push(int x){
      s1.push(x);
    }
    int pop(){
      if(s1.empty() && s2.empty()){ cout<<"Queue is empty"<<endl; return -1; }
      if(s2.empty()){
        while(!s1.empty()){
          s2.push(s1.top());
          s1.pop();
        }
      }
      int top_val = s2.top();
      s2.pop();
      return top_val;
    }
    
    bool empty(){
      return ( s1.empty() && s2.empty() );
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