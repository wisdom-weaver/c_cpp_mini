#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=a;i<b;i++)
#define vi vector<int>
const int N=102, MOD=1e9+7, inf=1e9;
int n,m,k;
vi a, b;
int dp[2005][2005][7];

int solve(int i, int j, int k){
  if(dp[i][j][k]!=-1) return dp[i][j][k];
  if(i==n || j==m) return 0;
  int c1=0,c2=0,c3=0;
  if(a[i]==b[j])
    c1 = 1+solve(i+1,j+1,k);
  if(k>0)
    c2 = 1+solve(i+1,j+1,k-1);
  c3 = max(solve(i+1,j,k), solve(i,j+1,k));
  return dp[i][j][k] = max({c1,c2,c3});
}

int main(){
  memset(dp,-1,sizeof(dp));
  cin>>n>>m>>k;
  a = vi(n);
  b = vi(m);
  for(auto&i: a) cin>>i;
  for(auto&i: b) cin>>i;
  cout<<solve(0,0,k);
  return 0;
}
