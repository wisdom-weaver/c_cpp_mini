#include <bits/stdc++.h>
using namespace std;

#define pii pair<int, int>
#define vi vector<int>
#define vii vector<pii>
#define ff first
#define ss second
#define rep(i, a, b) for (int i = a; i < b; i++)

int main(){
  vi a = {5,4,3,-3,-4,-5};
  vi prefix; int sum=0;
  map<int,int> mp;
  rep(i,0,a.size()){
    prefix.push_back(sum+=a[i]);
    cout<<a[i]<<" ";
  }cout<<endl;
  
  rep(i,0,prefix.size()){
    mp[prefix[i]]++;
    cout<<prefix[i]<<" ";
  }cout<<endl;
  
  int ans=0;
  map<int,int>::iterator it;
  for(it=mp.begin(); it!=mp.end(); it++){
    cout<<it->ff<<": "<<it->ss<<endl;
    int c = it->ss;
    ans += (c*(c-1))/2;
    if(it->ff==0)
      ans += c;
  }
  cout<<"no of subarrays with sum zero: "<<ans<<endl;

    
    
  return 0;
}