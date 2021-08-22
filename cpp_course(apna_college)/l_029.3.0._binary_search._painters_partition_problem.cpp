#include <bits/stdc++.h>
using namespace std;

int find_feasible(int ar[], int n, int limit){
  int sum=0, painters=1;
  for(int i=0;i<n;i++){
    sum+=ar[i];
    if(sum>limit){
      sum=ar[i];
      painters++;
    }
  }
  return painters;
}

int painters_partition(int ar[], int n, int m){
  int tot_len=0, k=INT_MIN;
  for(int i=0;i<n;i++){
    tot_len+=ar[i];
    k = max(k,ar[i]);
  }

  int low=k, high=tot_len;
  while(low<high){
    int mid = (low+high)/2;
    int painters = find_feasible(ar,n,mid);
    if(painters<=m)
      high=mid;
    else 
      low=mid+1;
  }
  return low;
}

int main(){
  int ar[]={10,20,30,40};
  int n=4, m=2;
  cout<<"painters_partition: "<<painters_partition(ar,n,m)<<endl;
  return 0;
}