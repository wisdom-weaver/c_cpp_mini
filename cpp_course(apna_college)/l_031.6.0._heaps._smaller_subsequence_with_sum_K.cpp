#include <bits/stdc++.h>
using namespace std;

#define pii pair<int, int>
#define vi vector<int>
#define vii vector<pii>
#define ff first
#define ss second
#define rep(i, a, b) for (int i = a; i < b; i++)

int smallest_subsequence_with_sumK(vi a, int k){
  int sum=0, c=0;
  priority_queue<int, vi> pq;
  rep(i,0,a.size())
    pq.push(a[i]);

  while(!pq.empty()){
    sum+=pq.top(); pq.pop();
    c++;
    if(sum>=k) return c;
  }
  return sum<k?-1:c;
}

int main()
{
  vi a = {1,1,3,2,8};
  int k = 12;
  cout<<smallest_subsequence_with_sumK(a,k)<<endl;

  return 0;
}