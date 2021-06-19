#include <iostream>
using namespace std;

#define N 100

class stack{
  int *arr;
  int top;
  public: 
    stack(){
      arr = new int [N];
      top = -1;
    }
    
    void push(int x){
      if(top==N-1){
        cout<<"Stack Overflow"<<endl;
        return;
      }
      top++;
      arr[top] = x;
    }
    
    void pop(){
      if(top==-1){
        cout<<"No element to pop"<<endl;
        return;
      }
      top--;
    }

    int get_top(){
      if(top == -1){
        cout<<"No element in stack"<<endl;
        return -1;
      }
      return arr[top];
    }
    
    bool is_empty(){
      return top==-1;
    }

    void display(){
      if(top==-1){ cout<<"empty stack"<<endl; return; }
      int i=-1; 
      while(++i<=top){
        cout<<arr[i]<<" > ";
      }
      cout<<" top "<<endl;
    }

};

int main(){
  stack st;
  cout<<"stack: "; st.display();
  int i=0,n=4; while(i<n)st.push(++i);
  cout<<"stack: "; st.display();
  cout<<"top value : "<<st.get_top()<<endl;
  cout<<"> pop operation"<<endl; st.pop();
  cout<<"stack: "; st.display();
  cout<<"> pop operation"<<endl; st.pop();
  cout<<"> pop operation"<<endl; st.pop();
  cout<<"stack: "; st.display();
  cout<<"> pop operation"<<endl; st.pop();
  cout<<"stack: "; st.display();
  cout<<"> pop operation"<<endl; st.pop();
  cout<<"stack: "; st.display();
  return 0;
}