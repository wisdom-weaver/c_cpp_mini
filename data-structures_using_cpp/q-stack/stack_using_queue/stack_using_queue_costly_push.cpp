#include <bits/stdc++.h>
using namespace std;

class stack_{
  int N;
  queue<int> q1;
  queue<int> q2;
public:
  stack_(){ N=0; }

  void push(int val){
    q2.push(val);
    // empty q1 onto q2
    while(!q1.empty()) {
      q2.push(q1.front());
      q1.pop();
    }
    N++;

    //swap queues
    queue<int> temp = q1;
    q1 = q2;
    q2 = temp;
  }

  void pop(){
    if(q1.empty()) return;
    q1.pop(); N--;
  }
  
  int top(){
    if(q1.empty()){cout<<"Underflow"; return-1;};
    return q1.front();
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
  return 0;
}