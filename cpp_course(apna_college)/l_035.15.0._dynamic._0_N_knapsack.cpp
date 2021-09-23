#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=a;i<b;i++)
#define vi vector<int>
const int N=102, MOD=1e9+7, inf=1e9;

int main(){
  int n=5, W=11;
  vi wt = {3,2,4,5,1};
  vi val = {4,3,5,6,1};
  vi dp(W+1,0);
  for(int j=0; j<=W; j++){
    for(int i=0;i<n;i++){
      if(j-wt[i]>=0)
        dp[j] = max(dp[j], val[i]+dp[j-wt[i]]);
    }
  }
  cout<<dp[W];
  return 0;
}
