#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=a;i<b;i++)
#define vi vector<int>
const int N=102, MOD=1e9+7, inf=1e9;

vi a; int dp[100][100];

int solve(int i, int j){
  if(i==j) return a[i];
  if(i>j) return 0;
  if(dp[i][j]!=-1) return dp[i][j];
  int pick_f = a[i] + min(solve(i+2,j), solve(i+1, j-1));  
  int pick_l = a[j] + min(solve(i,j-2), solve(i+1, j-1));
  return dp[i][j] = max(pick_f, pick_l);
}

int main(){
  memset(dp, -1, sizeof(dp));
  int n; cin>>n;
  a = vi(n);
  for(int i=0;i<n;i++) cin>>a[i];

  cout<<solve(0,n-1);

  return 0;
}
