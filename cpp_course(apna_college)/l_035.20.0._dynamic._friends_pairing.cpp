#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=a;i<b;i++)
#define vi vector<int>
const int N=102, MOD=1e9+7, inf=1e9;

int main(){
  int n=3;
  vi dp(n+1,0);
  dp[0]=1;
  dp[1]=1;
  rep(i,2,n+1)
    dp[i] = dp[i-1] + (i-1)*dp[i-2];
  cout<<dp[n];
  return 0;
}
