#include <bits/stdc++.h>
using namespace std;

bool is_palin(int n){
  int r=0, sn=n;
  while(n){
    r = r*10+n%10;
    n/=10;
  }
  return r==sn;
}

int subarr_with_palincat(vector<int> arr, int k){
  int num=0;
  for(int i=0;i<k;i++) num = num*10 + arr[i];
  if(is_palin(num)) return 0;

  for(int i=k; i<arr.size(); i++){
    num = (num % (int)(pow(10,k-1)))*10 + arr[i];
    if(is_palin(num)) return i-k+1;
  }
  return -1;
}

int main(){
  vector<int> arr={2,3,5,1,1,5};
  int k=4;
  int ans = subarr_with_palincat(arr,k);
  if(ans==-1)
    cout<<"no such subarr";
  else  
    for(int i=ans;i<ans+k;i++)
      cout<<arr[i]<<" ";
  return 0;
}