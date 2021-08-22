#include <bits/stdc++.h>
using namespace std;

int peak_elem(int ar[], int low, int high, int n){
  if(low>high) return -1;
  int mid = low+(high-low)/2;
  if(
    (mid==0  ||ar[mid-1]<=ar[mid]) && 
    (mid==n-1||ar[mid+1]<=ar[mid])
  ) return mid;

  if(mid>0 && ar[mid-1]>ar[mid])
    return peak_elem(ar, low, mid-1, n);
  else 
    return peak_elem(ar, mid+1, high, n);
}

int main(){
  int ar[]={0,6,8,5,7,9};
  int n=sizeof(ar)/sizeof(ar[0]);
  int idx = peak_elem(ar,0,n-1,n);
  if(idx==-1)
    cout<<"no peak_elem"<<endl;
  else 
    cout<<"peak_elem: "<<ar[idx]<<" at ar["<<idx<<"]"<<endl;
  return 0;
}