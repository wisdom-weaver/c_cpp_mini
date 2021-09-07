#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=a;i<b;i++)
#define vi vector<int>
const int N=1e3+2, MOD=1e9+7;
int dp[N];

// memoization
int lis(vi&a, int n){
  if(dp[n]!=-1) return dp[n];
  dp[n] = 1;
  rep(i,0,n)
    if(a[n]>a[i])
      dp[n] = max(dp[n], 1+lis(a,i));
  return dp[n];
}

// tabulation
int lis2(vi&a){
  int n = a.size();
  vi dpp(n,1);
  int ans=0;
  rep(i,1,n){
    rep(j,0,i){
      if(a[i]>a[j]) 
        dp[i] = max(dp[i], 1+dp[j]);
    }
    ans = max(ans, dp[i]);
  }
  return ans;
}

int main(){
  rep(i,0,N) dp[i]=-1;

  int n; cin>>n;
  vi a(n);
  rep(i,0,n) cin>>a[i];

  cout<<"longest inc. subseq: "<<lis(a,n-1)<<"\n";
  cout<<"longest inc. subseq: "<<lis2(a)<<"\n";

  

  return 0;
}
