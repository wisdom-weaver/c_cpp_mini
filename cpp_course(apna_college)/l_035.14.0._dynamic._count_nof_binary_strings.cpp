#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=a;i<b;i++)
#define vi vector<int>
const int N=102, MOD=1e9+7, inf=1e9;

// no of binary strings you can form of length N such that there are no consecutive 1's
int main(){
  int n; cin>>n;
  vi fib(n+2,0);
  fib[0]=1;
  fib[1]=1;
  for(int i=2;i<=n+1;i++)
    fib[i] = fib[i-1]+fib[i-2];
  cout<<fib[n+1];

  return 0;
}
