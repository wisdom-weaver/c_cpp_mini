#include <bits/stdc++.h>
using namespace std;

int main(){
  vector<vector<int>> v={
    // {start, end}
    {10,20},
    {7,15},
    {20,30},
  };
  int n = v.size();
  sort(
    v.begin(),v.end(),
    [&](vector<int>&a, vector<int>&b){
      return a[1]<b[1];
    }
  );
  int take=1;
  int end = v[0][1];
  for(int i=1;i<v.size(); i++){
    if(v[i][0]>=end){
      take++;
      end = v[i][1];
    }
  }
  cout<<"max activities: "<<take;
  return 0;
}