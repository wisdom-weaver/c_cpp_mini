#include <bits/stdc++.h>
using namespace std;

const int N=1e5+2, MOD=1E9+7;
int dp[N];

int min_sq(int n){
  //memoization
  if(n<=3) return n;
  if(dp[n]!=MOD)
    return dp[n];
  for(int i=1;i*i<=n;i++){
    dp[n] = min(dp[n], 1+min_sq(n-i*i));
  }
  return dp[n];
}

int main(){

  for(int i =0;i<N;i++) 
    dp[i]=MOD;
   int n; cin>>n;
  cout<<"min_sq: "<<min_sq(n)<<endl;

  // tabulation
  vector<int> dpp(n+1,MOD);
  dpp[0]=0;
  dpp[1]=1;
  dpp[2]=2;
  dpp[3]=3;
  for(int i=1;i*i<=n;i++)
    for(int j=0;i*i+j<=n;j++)
      dpp[i*i+j] = min(dpp[i*i+j], 1+dpp[j]);
  cout<<"min_sq: "<<dpp[n]<<endl;

  return 0;
}

/*
*/