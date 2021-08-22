#include <bits/stdc++.h>
using namespace std;

int find_pivot(int ar[], int n){
  for(int i=0;i<n-1;i++)
    if(ar[i]>ar[i+1]) return i;
  return -1;
}

int search_in_rotated_ar(int ar[], int key, int left, int right){
  if(left>right) return -1;
  int mid = (left+right)/2;
  if(ar[mid]==key) return mid;

  if(ar[left]<=ar[mid]){
    if(key>=ar[left] && key<=ar[mid])
      return search_in_rotated_ar(ar, key, left, mid-1);
    else 
      return search_in_rotated_ar(ar, key, mid+1, right);
  }else{
    if(key>=ar[left] && key<=ar[mid])
      return search_in_rotated_ar(ar, key, left, mid-1);
    else 
      return search_in_rotated_ar(ar, key, mid+1, right);
  }

}

int main(){
  int ar[]={6,7,8,9,10,11,1,2,5};
  int key=2, n=sizeof(ar)/sizeof(ar[0]);
  cout<<"search_in_rotated_ar: "<<search_in_rotated_ar(ar,key,0,n-1)<<endl;
  return 0;
}