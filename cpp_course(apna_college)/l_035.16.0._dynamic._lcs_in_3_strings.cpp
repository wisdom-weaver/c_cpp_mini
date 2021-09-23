#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=a;i<b;i++)
#define vi vector<int>
const int N=102, MOD=1e9+7, inf=1e9;
const int n=205;
int dp[n][n][n];

int LCS(string&s1, string&s2, string&s3, int i, int j, int k){
  if(dp[i][j][k]!=-1) return dp[i][j][k];
  if(i==0||j==0||k==0) return 0;
  if(s1[i-1]==s2[j-1] && s2[j-1]==s3[k-1])
    return dp[i][j][k] = 1+ LCS(s1,s2,s3,i-1,j-1,k-1);
  int l = LCS(s1,s2,s3,i-1,j,k);
  int r = LCS(s1,s2,s3,i,j-1,k);
  int p = LCS(s1,s2,s3,i,j,k-1);
  return dp[i][j][k] = max({l,r,p});
}

int main(){
  memset(dp,-1,sizeof(dp));
  string s1; cin>>s1;   
  string s2; cin>>s2;   
  string s3; cin>>s3;   
  cout<<LCS(s1,s2,s3, s1.size(), s2.size(), s3.size());
  return 0;
}
