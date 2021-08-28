#include <bits/stdc++.h>
using namespace std;

#define pii pair<int,int>
#define v_pii vector<pii>

int min_stops(v_pii a, int l, int p){
  int ans = 0, curr=p, flag=0;
  for(int i=0;i<a.size();i++)
    a[i].first = l-a[i].first;

  sort(a.begin(), a.end());
  priority_queue<int,vector<int>> pq;
  for(int i=0;i<a.size();i++){
    if(curr>=l) break;
    while(curr<a[i].first){
      if(pq.empty()){ flag=1; break; }
      curr+=pq.top(); pq.pop();
      ans++;
    }
    if(flag) break;
    pq.push(a[i].second);
  }
  return flag?-1:ans;
}

int main(){
  v_pii a={
    {4, 4},
    {5, 2},
    {11, 5},
    {15, 10},
  };
  int l=25, p=10;

  cout<<"min_stops: "<<min_stops(a, l, p);
  return 0;
}