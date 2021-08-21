#include <bits/stdc++.h>
using namespace std;

bool is_feasible(int ar[], int n, int m, int mix){
  int students_req=1, sum=0;
  for(int i=0;i<n;i++){
    if(ar[i]>mix)
      return false;
    if(sum+ar[i]>mix){
      students_req++;
      sum=ar[i];
      if(students_req>m) return false;
    }else{
      sum+=ar[i];
    }
  }
  return true;
}

int allocate_min_pages(int ar[], int n, int m){
  int sum = 0;
  if(n < m) return -1;
  
  for(int i=0;i<n;i++) sum+=ar[i];
  int start=0, end=sum, ans=INT_MAX;

  while(start<=end){
    int mid = (start+end)/2;
    if(is_feasible(ar,n,m,mid)){
      ans = min(ans, mid);
      end = mid-1;
    }else{
      start = mid+1;
    }
  }
  return ans;
}

int main(){
  int ar[]={12,34,67,90};
  int n=4, m=2;
  cout<<"allocate_min_pages: "<<allocate_min_pages(ar,n,m)<<endl;
  return 0;
}