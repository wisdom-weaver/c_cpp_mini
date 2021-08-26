#include <bits/stdc++.h>
using namespace std;

int min_compute_time(vector<int>v){
  priority_queue<int, vector<int>, greater<int>> min_heap;
  for(auto i:v)
    min_heap.push(i);
  
  int ans=0;
  while(min_heap.size()>1){
    int el1 = min_heap.top(); min_heap.pop();
    int el2 = min_heap.top(); min_heap.pop();
    ans += el1+el2;
    min_heap.push(el1+el2);
  }
  return ans;
}

int main(){
  vector<int> v={5,4,2,7};
  cout<<"min_compute_time: "<<min_compute_time(v);
  return 0;
}