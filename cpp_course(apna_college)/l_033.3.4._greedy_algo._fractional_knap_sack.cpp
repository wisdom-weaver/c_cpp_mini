#include <bits/stdc++.h>
using namespace std;

int main(){
  vector<pair<int,int>> v={
    // {value, wt}
    {21, 7},
    {24, 4},
    {12, 6},
    {40, 5},
    {30, 6}
  };
  int w = 20;
  sort(
    v.begin(),
    v.end(),
    [&](pair<int,int>&a, pair<int,int>&b){
      return (double)(a.first/a.second) > (double)(b.first/b.second);
    }
  );

  int ans = 0;
  for(int i=0; i<v.size() && w!=0; i++){
    if(w>=v[i].second){
      ans += v[i].first;
      w -= v[i].second;
      continue;
    }
    double vw = (double)(v[i].first/v[i].second);
    ans += vw*w;
    w=0;
  }
  cout<<"max value possible to stuff in sack: "<<ans;


  return 0;
}