#include <bits/stdc++.h>
using namespace std;

class stack_{
  int N;
  queue<int> q1;
  queue<int> q2;
public:
  stack_(){ N=0; }

  void push(int val){
    q1.push(val);
    N++;
  }

  void pop(){
    if(size()==0){ return; }

    // pop q1 into q2 except the last element
    while(q1.size()!=1){
      q2.push(q1.front()); 
      q1.pop();
    }
    // pop out the last element
    q1.pop();
    N--;

    //swap the queues
    queue<int> temp = q1;
    q1 = q2;
    q2 = temp;
  }
  
  int top(){
    if(size()==0){cout<<"Underflow"; return -1;};
    // pop q1 into q2 except the last element
    while(q1.size()!=1){
      q2.push(q1.front()); 
      q1.pop();
    }
    // pop out the last element
    int top_val = q1.front();
    q2.push(top_val);
    //swap the queues
    queue<int> temp = q1;
    q1 = q2;
    q2 = temp;
    return top_val;
  }

  int size(){
    return N;
  }
    
};

int main(){
  stack_ st;
  st.push(1);
  st.push(2);
  st.push(3);
  st.push(4);

  cout<<st.top()<<endl; st.pop();
  cout<<st.top()<<endl; st.pop();
  cout<<st.top()<<endl; st.pop();
  cout<<st.top()<<endl; st.pop();
  cout<<st.top()<<endl; st.pop();
  cout<<st.top()<<endl; st.pop();
  cout<<st.top()<<endl; st.pop();
  cout<<st.top()<<endl; st.pop();
  cout<<st.top()<<endl; st.pop();
  cout<<st.top()<<endl; st.pop();
  cout<<st.top()<<endl; st.pop();
  cout<<st.top()<<endl; st.pop();
  return 0;
}