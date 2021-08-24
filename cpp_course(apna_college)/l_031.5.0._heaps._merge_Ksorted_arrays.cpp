#include <bits/stdc++.h>
using namespace std;

#define pii pair<int, int>
#define vi vector<int>
#define vii vector<pii>
#define ff first
#define ss second
#define rep(i, a, b) for (int i = a; i < b; i++)

int main()
{
  vector<vi> a = {
    {1,4,6},
    {2,3},
    {5,6,7},
  };
  int k = a.size();

  vi idx(a.size(),0);
  priority_queue<pii,vii, greater<pii>> pq;
  rep(i,0,k) 
    pq.push({ a[i][0], i });
  
  vi ans;
  while(!pq.empty()){
    pii x = pq.top(); pq.pop();
    ans.push_back(x.ff);
    int ar_no = x.ss;
    if(idx[ar_no]+1 < a[ar_no].size()){
      int value = a[ar_no][idx[ar_no]+1];
      pq.push({ value, ar_no });
      idx[ar_no]+=1;
    }
  }

  rep(i,0,ans.size())
    cout<<ans[i]<<" ";

  return 0;
}