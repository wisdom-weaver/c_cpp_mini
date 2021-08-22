#include <bits/stdc++.h>
using namespace std;

// int is_perfect(int n){
//   int r=0;
//   for(int i=1; i<(n); i++) 
//     if(n%i==0) r+=i;
//   return r==n?1:0;
// }

int is_perfect(int n){
  int r=1;
  for(int i=2; i<sqrt(n); i++) 
    if(n%i==0){
      if(i==i/n) r += i;
      else r += i+n/i;
    }
  return r==n?1:0;
}

int max_sum(vector<int>arr, int k){
  int n= arr.size();
  if(n<k) return -1;
  
  int res=0;
  for(int i=0;i<k;i++) res+=arr[i];

  int sum = res;
  for(int i=k;i<n;i++){
    sum = sum + arr[i] - arr[i-k];
    res = max(sum, res);
  }
  return res;
}

int max_perfectNs(vector<int> arr, int k){
  for(int i=0; i<arr.size(); i++)
    arr[i] = is_perfect(arr[i]);

  return max_sum(arr, k);
}

int main(){
  vector<int> arr={28,2,3,6,496,99,8128,24};
  int k=4;
  int ans = max_perfectNs(arr,k);
  cout<<"max_perfectNs: "<<ans<<endl;
  return 0;
}