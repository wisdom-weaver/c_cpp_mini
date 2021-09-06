#include <bits/stdc++.h>
using namespace std;

bool is_cycle(int src, vector<vector<int>>adj, vector<bool>&visited, vector<bool>&stack){
  stack[src] = true;
  if(!visited[src]){
    visited[src]=true;
    for(auto i: adj[src]){
      if(!visited[i] && is_cycle(i,adj,visited,stack))
        return true;
      if(stack[i])
        return true;
    }
  }
  stack[src] = false;
  return false;
}

int main(){
  int n,m; cin>>n>>m;
  int cnt = 0;
  vector<vector<int>> adj(n);
  for(int i=0; i<m; i++){
    int u,v; cin>>u>>v;
    adj[u].push_back(v);
  }

  bool cycle=false;
  vector<bool> stack(n,0);
  vector<bool> visited(n,false);
  for(int i=0; i<n; i++){
    if(!visited[i] && is_cycle(i,adj,visited, stack)){
      cycle = true; break;
    }
  }

  if(cycle) cout<<"cycle is present";
  else cout<<"cycle is not present";

  return 0;
}

/*
4 3
0 1
1 2
2 1
cycle is present

4 2
0 1
2 3
cycle is not present
*/