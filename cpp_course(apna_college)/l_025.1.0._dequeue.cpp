#include <iostream>
#include <deque>
using namespace std;

void print_dq(deque<int>dq){
  cout<<"DQ: ";
  for(auto i: dq)
    cout<<i<<" ";
  cout<<endl;
}

int main()
{
  deque<int> dq;
  dq.push_front(1);
  dq.push_front(2);
  print_dq(dq);
  
  dq.push_back(3);
  dq.push_back(4);
  print_dq(dq);

  dq.pop_front();
  print_dq(dq);

  dq.pop_back();
  print_dq(dq);

  return 0;
}
