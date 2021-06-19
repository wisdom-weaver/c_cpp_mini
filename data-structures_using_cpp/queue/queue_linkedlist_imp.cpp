#include <iostream>
using namespace std;

class node{
  public:
    int data;
    node* next;

    node(int val){
      data = val;
      next = NULL;
    }
};

class queue{
  node* front;
  node* back;
  
public:
  queue(){
    front = NULL;
    back = NULL;
  }

  void push(int val){
    node* new_node = new node(val);
    
    if(front==NULL){
      back = new_node;
      front = new_node;
      return;
    }

    back->next = new_node;
    back = new_node;
  }

  void pop(){
    if(front==NULL){ cout<<"Queue Underflow"<<endl; return; }
    node* to_delete = front;
    front = front->next;
    delete to_delete;
  }

  int peek(){
    if(front==NULL){ cout<<"Queue is Empty"<<endl; return -1; }
    return front->data;
  }

  bool empty(){
    return front==NULL;
  }

};

int main(){
  queue q;
  int i=0,n=5; while(i<n) q.push(++i);
  i=0;
  do{
    cout<<q.peek()<<endl; q.pop();
  }while(++i<n+1);

  return 0;
}