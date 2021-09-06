#include <bits/stdc++.h>
using namespace std;

int n,m; 
vector<vector<int>> adj;
vector<bool> vis;
vector<int> components;

int get_comp(int idx){
  if(vis[idx])
    return 0;
  vis[idx]=true;
  int ans=1;
  for(auto i: adj[idx]){
    if(!vis[i]){
      ans+=get_comp(i);
      vis[i]=true;
    }
  }
  return ans;
}

int main(){
  cin>>n>>m;
  adj = vector<vector<int>>(n);
  vis = vector<bool>(n);
  for(int i=0; i<m; i++){
    int u,v; cin>>u>>v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  for(int i=0; i<n; i++){
    if(!vis[i])
      components.push_back(get_comp(i));
  }
  cout<<"\nnoof connected comps:"<<components.size()<<endl;
  cout<<"sizes: ";
  for(auto i: components){
    cout<<i<<" ";
  }

  cout<<"\n----\n";
  long long ans=0;
  for(auto i:components){
    ans+=i*(n-i);
  }
  ans=ans/2;
  cout<<"no of unique pairs from diff.comps: "<<ans;


  return 0;
}

/*
5 3
0 1
2 3
0 4

noof connected comps:2
sizes: 3 2 
----
no of unique pairs from diff.comps: 6
*/