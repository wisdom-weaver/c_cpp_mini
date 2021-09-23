#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=a;i<b;i++)
#define vi vector<int>
const int N=102, MOD=1e9+7, inf=1e9;

// bitonic -> first strictly inc. then strictly dec;
//            entirely strictly inc.
//            entirely strictly dec.

int main(){
  int n=8;
  vi a = {1,11,2,10,4,5,2,1};
  vi forward(n,1);
  vi backward(n,1);

  rep(i,0,n)
    rep(j,0,i)
      if(a[i]>a[j])
        forward[i] = max(forward[i], 1+forward[j]);
  
  // rep(i,0,n)
  //   rep(j,i,n)
  //     if(a[i]<a[j])
  //       backward[i] = max(backward[i], 1+backward[j]);

  for(int i=n-1; i>=0; i--)
    for(int j=n-1; j>i; j--)
      if(a[i]>a[j])
        backward[i] = max(backward[i], 1+backward[j]);

  int ans=0;
  rep(i,0,n){
    ans = max(ans, forward[i]+backward[i]-1);
  }
  cout<<ans;

  return 0;
}
