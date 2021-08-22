#include <bits/stdc++.h>
using namespace std;

#define vi vector<int> 
#define pi pair<int,int> 
#define vii vetcor<pii> 
#define rep(i,a,b) for(int i=a;i<b;i++)
#define ff first
#define ss second
#define setBits(x) builtin_popcount(x)

void heapify(vi&a, int n, int i){
  int mx_idx = i;
  int l = 2*i+1;
  int r = 2*i+2;

  if(l<n && a[l]>a[mx_idx]) mx_idx=l;
  if(r<n && a[r]>a[mx_idx]) mx_idx=r;

  if(mx_idx!=i){
    swap(a[i], a[mx_idx]);
    heapify(a,n,mx_idx);
  }

}

void heapsort(vi&a){
  int n = a.size();
  for(int i=n/2-1; i>=0; i--)
    heapify(a,n,i);
  for(int i=n-1; i>0; i--){
    swap(a[0], a[i]);
    heapify(a,i,0);
  }
  
}

int main(){
  vi a = {4,5,3,2,6,1};
  heapsort(a);
  rep(i,0,a.size())
    cout<<a[i]<<" ";
  return 0;
}