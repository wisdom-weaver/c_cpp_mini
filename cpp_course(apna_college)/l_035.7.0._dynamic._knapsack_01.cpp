#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=a;i<b;i++)

const int N=1e3+2, MOD=1e9+7;
int val[N], wt[N];
int dp[N][N];

int knapsack(int n, int w){
  if(w<=0) return 0;
  if(n<=0) return 0;
  if(dp[n][w]!=-1) return dp[n][w];
  if(wt[n-1]>w) return dp[n][w] = knapsack(n-1, w);
  return dp[n][w] = max( knapsack(n-1, w), knapsack(n-1,w-wt[n])+val[n] );
}

int main(){
  rep(i,0,N) rep(j,0,N) dp[i][j]=-1;

  int n; cin>>n;
  rep(i,0,n) cin>>wt[i];
  rep(i,0,n) cin>>val[i];
  int w;cin>>w;
  cout<<"knapsack: "<<knapsack(n,w);


  return 0;
}
