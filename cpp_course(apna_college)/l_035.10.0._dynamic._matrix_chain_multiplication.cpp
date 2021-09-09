#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=a;i<b;i++)
const int N=102, MOD=1e9+7;
int a[N];
int dp[N][N];

// memoization
int mcm(int i, int j){
  if(i==j) return 0;
  if(dp[i][j]!=-1) return dp[i][j];
  dp[i][j]=MOD;
  for(int k=i;k<j;k++){
    dp[i][j] = min(dp[i][j], mcm(i,k)+mcm(k+1,j)+a[i-1]*a[k]*a[j]);
  }
  return dp[i][j];
}

// tabulation
int mcm2(int a[],int n){
  int dpp[n][n];
  for(int i=1;i<n;i++)
    dpp[i][i]=0;
  for(int l=2;l<=n;l++){
    for(int i=1; i<n-l+1; i++){
      int j=i+l-1;
      dpp[i][j]=MOD;
      for(int k=i;k<j;k++){
        dpp[i][j] = min(dpp[i][j], dpp[i][k]+dpp[k+1][j]+a[i-1]*a[k]*a[j]);
      }
    }
  }
  return dpp[1][n-1];
}

int main(){
  memset(dp,-1,sizeof dp);

  int n; cin>>n;
  for(int i=0;i<n;i++) cin>>a[i];

  cout<<mcm(1,n-1)<<endl;
  cout<<mcm2(a,n)<<endl;

  return 0;
}
