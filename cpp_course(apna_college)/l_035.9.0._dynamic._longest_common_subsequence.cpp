#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=a;i<b;i++)
#define vi vector<int>
const int N=1e3+2, MOD=1e9+7;
int dp[N][N];

int lcs(string&s1, string&s2, int n, int m){
  if(n==0||m==0) return 0;
  if(dp[n][m]!=-1) return dp[n][m];
  if(s1[n-1]==s2[m-1])
    return dp[n][m] = 1+lcs(s1,s2,n-1,m-1);
  else 
    return dp[n][m] = max(lcs(s1,s2,n,m-1), lcs(s1,s2,n-1,m));
}

int main(){
  rep(i,0,N) rep(j,0,N) dp[i][j]=-1;

  string s1,s2; cin>>s1>>s2;
  int n=s1.size(), m=s2.size();
  cout<<"longest comm. subseq:"<<lcs(s1,s2,n,m)<<endl;
  return 0;
}
