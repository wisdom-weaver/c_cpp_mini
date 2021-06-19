#include <iostream>
#include <stack>
using namespace std;

void display(stack<int> st){
  cout<<" top ";
  while(st.size()){
    cout<<" < "<<st.top();
    st.pop();
  }
  cout<<endl;
}

void insert_at_bottom(stack<int> &st, int elem){
  if(st.empty()) return st.push(elem);
  int top_elem = st.top();
  st.pop();

  insert_at_bottom(st, elem);

  st.push(top_elem);

}

void reverse_stack(stack<int> &st){
  if(st.empty()) return;
  int elem = st.top();
  st.pop();
  reverse_stack(st);
  insert_at_bottom(st, elem);
}

int main(){
  stack<int> st;
 int i=0, n=5; while(i<n) st.push(++i);
  cout<<"stack : "; display(st);

  reverse_stack(st);
  cout<<"re_st : "; display(st);

  return 0;
}