#include <bits/stdc++.h>
using namespace std;

int min_size_subarr_sum_gtX(int ar[], int n, int x){
  int sum=0, min_len=n+1;
  int start=0, end=0;
  while(end<n){
    while(sum<=x && end<n)
      sum+=ar[end++];
    while(sum>x && start<n){
      sum = sum-ar[start++];
      min_len = min(min_len, end-start+1);
    }
  }
  return min_len;
}

int main(){
  int ar[]={1,4,45,6,10,19};
  int n=sizeof(ar)/sizeof(ar[0]);
  int sum=0, x=51;
  int min_len = min_size_subarr_sum_gtX(ar,n,x);
  if(min_len==n+1)
    cout<<"no such subarray"<<endl;
  else
    cout<<"min_size_subarr_sum_gtX: "<<min_len<<endl;
  return 0;
}