#include <bits/stdc++.h>
using namespace std;

int max_subarr_sum(int ar[], int n, int k, int x){
  int sum=0, ans=INT_MIN;
  for(int i=0;i<k;i++)
    sum+=ar[i];
  if(sum<x) ans =sum;

  for(int i=k;i<n;i++){
    sum = sum - ar[i-k]+ ar[i];
    if(sum<x)
     ans = max(ans, sum);
  }
  return ans;
}

int main(){
  int ar[]={7,5,4,6,8,9};
  int n=sizeof(ar)/sizeof(ar[0]);
  int k=3, x=20;
  cout<<"max_subarr_sum: "<<max_subarr_sum(ar,n,k,x)<<endl;
  return 0;
}