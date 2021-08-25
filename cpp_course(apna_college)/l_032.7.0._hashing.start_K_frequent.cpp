#include <bits/stdc++.h>
using namespace std;

#define pii pair<int, int>
#define vi vector<int>
#define vii vector<pii>
#define ff first
#define ss second
#define rep(i, a, b) for (int i = a; i < b; i++)


int main(){
  vi a = {1,2,2,2,3,1};
  int k=2;
  map<int,int> freq;
  rep(i,0,a.size()){
    int present_size = freq.size();
    if(freq[a[i]]==0 && present_size==k)
      break;
    freq[a[i]]++;
  }

  vii ans;
  map<int,int>::iterator it;
  for(it=freq.begin(); it!=freq.end(); it++){
    
    if(it->ss!=0)
      ans.push_back({it->ss, it->ff});
  }
  sort(ans.begin(),ans.end(), greater<pii>());

  vii::iterator it2;
  for(it2=ans.begin(); it2!=ans.end(); it2++)
    cout<<it2->ss<<"=> "<<it2->ff<<endl;
    
  return 0;
}