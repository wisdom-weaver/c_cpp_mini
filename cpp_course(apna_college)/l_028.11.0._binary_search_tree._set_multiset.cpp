#include <bits/stdc++.h>
using namespace std;

int main(){
  cout<<"set"<<endl;
  set<int> s;
  s.insert(1);
  s.insert(2);
  s.insert(3);
  s.insert(3);
  s.insert(3);
  s.insert(5);
  for(auto i:s) cout<<i<<" "; cout<<endl;
  cout<<"size: "<<s.size()<<endl;
  cout<<(*s.lower_bound(3))<<endl;
  cout<<(*s.upper_bound(4))<<endl;
  cout<<(s.upper_bound(5)==s.end())<<endl;

  s.erase(2);
  s.erase(s.begin());
  for(auto i:s) cout<<i<<" "; cout<<endl;
  cout<<"------"<<endl;

  cout<<"multiset"<<endl;
  multiset<int> ms;
  ms.insert(1);
  ms.insert(2);
  ms.insert(2);
  ms.insert(2);
  ms.insert(3);
  ms.insert(3);
  ms.insert(3);
  for(auto i: ms) cout<<i<<" "; cout<<endl;
  cout<<"size: "<<ms.size()<<endl;

  ms.erase(3); // delete all occurance
  ms.erase(ms.find(2)); // delete one occurance
  for(auto i:ms) cout<<i<<" "; cout<<endl;
  cout<<"------"<<endl;

  cout<<"unordered_set"<<endl;
  unordered_set<int> us;
  us.insert(1);
  us.insert(1);
  us.insert(1);
  us.insert(3);
  us.insert(2);
  us.insert(5);
  for(auto i: us) cout<<i<<" "; cout<<endl;
  us.erase(us.find(3));
  for(auto i: us) cout<<i<<" "; cout<<endl;


  return 0;
}