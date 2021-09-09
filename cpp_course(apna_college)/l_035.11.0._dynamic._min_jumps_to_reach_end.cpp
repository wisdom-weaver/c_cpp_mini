#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=a;i<b;i++)
#define vi vector<int>
const int N=102, MOD=1e9+7, inf=1e9;

int main(){

  int n; cin>>n;
  vi a(n);
  for(int i=0;i<n;i++) cin>>a[i];

  vi jumps(n, inf);
  if(a[0]==0) {
    cout<<"inf";
    return 0;
  }
  jumps[0]=0;
  rep(i,1,n){
    rep(j,0,i){
      if(i<=j+a[j]){
        jumps[i]=min(jumps[i], jumps[j]+1);
        break;
      }
    }
  }
  cout<<jumps[n-1];

  return 0;
}
