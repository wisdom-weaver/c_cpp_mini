#include <iostream>
#include <deque>
using namespace std;

int main(){
  deque<int> dq;
  dq.push_back(1);
  dq.push_back(2);
  dq.push_front(3);
  dq.push_front(4);

  cout<<"dq: ";for(auto i: dq) cout<<i<<" "; cout<<endl;

  dq.pop_back();
  dq.pop_front();
  cout<<"dq: ";for(auto i: dq) cout<<i<<" "; cout<<endl;
  cout<<"size => "; cout<<dq.size()<<endl;

  return 0;
}