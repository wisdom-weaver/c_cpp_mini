#include <iostream>
using namespace std;

const int N = 10;

class queue{
  int* arr;
  int front;
  int back;
  
  public:
  queue(){
    arr = new int [N];
    front = -1;
    back = -1;
  }
  
  // add element to the queue // push()
  void enqueue(int val){
    // if no space left
    if(back == N-1){ cout<<"Overflow"<<endl; return; }

    back++;
    arr[back] = val;
    
    // if queue was empty
    if(front==-1) front++;
  }
  
  // remove element from queue // pop()
  void dequeue(){
    if(front==-1 || front>back){
      cout<<"No elements in queue"<<endl;
      return;
    }
    front++;
  }
  
  // function to see the first element in the queue
  int peek(){
    if(front==-1 || front>back){
      cout<<"No elements in queue"<<endl;
      return -1;
    }
    return arr[front];
  }

  bool empty(){
    return (front==-1 || front>back);
      
  }

};

int main(){
  queue q;
  int i=0,n=5; while(i<n) q.enqueue(++i);
  
  i=0;
  while(++i<n+2){
    cout<<q.peek()<<endl; q.dequeue();
  }
  return 0;
}