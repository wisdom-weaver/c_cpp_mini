#include <bits/stdc++.h>
using namespace std;

int main(){
  int n,m; cin>>n>>m;
  int cnt = 0;
  vector<vector<int>> adj(n);
  vector<int> in_deg(n,0);
  for(int i=0; i<m; i++){
    int u,v; cin>>u>>v;
    adj[u].push_back(v);
    in_deg[v]++;;
  }

  queue<int>pq;
  for(int i=0; i<n; i++)
    if(in_deg[i]==0)
      pq.push(i);
  
  while(!pq.empty()){
    cnt++;
    int x = pq.front(); pq.pop();
    cout<<x<<" ";
    for(auto it: adj[x]){
      in_deg[it]--;
      if(in_deg[it]==0)
        pq.push(it);
    }
  }

  return 0;
}

/*
4 3 // directed acyclic graph
0 1
1 2
2 3
0 1 2 3 // -> topological order


3 3 // cyclic graph
0 1
1 2
2 0
    // no topological order
*/