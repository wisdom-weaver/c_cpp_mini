#include <bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
const int INF = 1e9;


int main(){
  int n,m; cin>>n>>m;
  vector<vector<int>> edges;
  for(int i=0;i<m;i++){
    int u,v,w; cin>>u>>v>>w;
    edges.push_back({u,v,w});
  }
  int src; cin>>src;
  
  vector<int> dist(n,INF);
  dist[src]=0;
  for(int it=0; it<n-1; it++){
    for(auto e: edges){
      int u = e[0];
      int v = e[1];
      int w = e[2];
      dist[v] = min(dist[v], dist[u]+w);
    }
  }

  cout<<"----\n"<<endl;
  for(auto i: dist){
    cout<<i<<" ";
  }

  return 0;
}

/*
5 8
1 2 3
3 2 5
1 3 2
3 1 1
1 4 2
0 2 4
4 3 -3
0 1 -1
0
----

0 -1 2 -2 1 
*/