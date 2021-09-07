#include <bits/stdc++.h>
using namespace std;

const int N=1e5+2;
int dp[N];

int fib(int n){
  if(n==0) return 0;
  if(n==1) return 1;
  if(n==2) return 1;
  if(dp[n]!=-1) return dp[n];
  else dp[n] = fib(n-1)+fib(n-2);
  return dp[n];
}

int main(){

  for(int i=0;i<N;i++) dp[i]=-1;

  int n; cin>>n;
  cout<<"fibo: "<<fib(n)<<endl;
}

/*
*/