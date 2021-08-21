#include <bits/stdc++.h>
using namespace std;

bool is_feasible(int mid, int ar[], int n, int k){
  int pos = ar[0], els =1;
  for(int i=1; i<n; i++){
    if(ar[i]-pos >= mid){
      pos = ar[i];
      els++;
      if(els==k) return true;
    } 
  }
  return false;
}

int largest_min_dist(int ar[], int n, int k){
  sort(ar, ar+n);
  int result = -1;
  int left=1, right=ar[n-1];
  while(left<right){
    int mid = (left+right)/2;
    if(is_feasible(mid, ar, n, k)){
      result = max(result, mid);
      left = mid+1;
    }else{
      right = mid;
    }
  }
  return result;
}

int main(){
  int ar[]={1,2,8,4,9};
  int n=5, k=3;
  cout<<"largest_min_dist: "<<largest_min_dist(ar,n,k)<<endl;
  return 0;
}