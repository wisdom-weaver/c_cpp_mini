#include <bits/stdc++.h>
using namespace std;

pair<int,int> compute_n_from_subarr(vector<int> arr, int k){
  int sum=0;
  for(int i=0;i<k;i++) sum+=arr[i];
  if(sum%3==0) return make_pair(0,k-1);

  for(int j=k;j<arr.size();j++){
    sum += arr[j] - arr[j-k];
    if(sum%3==0) return make_pair(j-k+1, j);
  }

  return make_pair(-1,-1);
}

int main(){
  vector<int> arr={84,23,45,12,56,82};
  int k=3;
  pair<int,int> ans = compute_n_from_subarr(arr,k);
  if(ans.first==-1)
    cout<<"no such subarr";
  else  
    for(int i=ans.first;i<=ans.second;i++)
      cout<<arr[i]<<" ";
  return 0;
}