#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=a;i<b;i++)
#define vi vector<int>
const int N=102, MOD=1e9+7, inf=1e9;

int main(){
  int n; cin>>n;
  vi a(n);
  rep(i,0,n)
    cin>>a[i];
  
  int curr=0, mx=0;
  rep(i,0,n){
    curr+=a[i];
    if(curr<0) curr=0;
    mx = max(curr,mx);
  }
  cout<<mx;

  return 0;
}
