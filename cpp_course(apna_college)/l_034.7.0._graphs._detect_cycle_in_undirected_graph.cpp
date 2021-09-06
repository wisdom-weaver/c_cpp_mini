#include <bits/stdc++.h>
using namespace std;

bool is_cycle(int src, vector<vector<int>>adj, vector<bool>visited, int parent){
  visited[src] = true;
  for(auto i: adj[src]){
    if(i!=parent){
      if(visited[i]) 
        return true;
      if(!visited[i] && is_cycle(i, adj, visited, src))
        return true;
    }
  }
  return false;
}

int main(){
  int n,m; cin>>n>>m;
  int cnt = 0;
  vector<vector<int>> adj(n);
  for(int i=0; i<m; i++){
    int u,v; cin>>u>>v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  bool cycle=false;
  vector<bool> visited(n,false);
  for(int i=0; i<n; i++){
    if(!visited[i] && is_cycle(i,adj,visited, -1)){
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
2 0
cycle is present

4 2
0 1
1 2
cycle is not present
*/