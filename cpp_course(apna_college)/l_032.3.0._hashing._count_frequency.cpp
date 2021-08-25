#include <bits/stdc++.h>
using namespace std;

#define pii pair<int, int>
#define vi vector<int>
#define vii vector<pii>
#define ff first
#define ss second
#define rep(i, a, b) for (int i = a; i < b; i++)


int main(){
  vi a = {1,2,2,2,1,1,4,3,4,1};
  unordered_map<int,int> freq;
  rep(i,0,a.size())
    freq[a[i]]++;

  unordered_map<int,int>::iterator it;
  for(it=freq.begin(); it!=freq.end(); it++)
    cout<<it->first<<" = "<<it->second<<endl;

  return 0;
}