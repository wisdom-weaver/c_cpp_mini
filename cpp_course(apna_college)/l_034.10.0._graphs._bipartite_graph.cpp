#include <bits/stdc++.h>
using namespace std;

vector<vector<int>>adj;
vector<bool>vis;
vector<int>color;
bool bipart=true;

void do_color(int u, int curr){
  if(color[u]!=-1 && color[u]!=curr){
    bipart = false;
    return;
  }
  color[u]=curr;
  
  if(vis[u]) return;
  else vis[u]=true;

  for(auto i: adj[u]){
    do_color(i, curr xor 1);
  }
}

int main(){
  int n,m; cin>>n>>m;
  adj = vector<vector<int>>(n);
  vis = vector<bool>(n,false);
  color = vector<int>(n,-1);

  for(int i=0;i<n;i++){
    int u,v; cin>>u>>v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  for(int i=0;i<n;i++){
    if(!vis[i]){
      do_color(i,0);
    }
  }
  if(bipart)
    cout<<"graph is bipart"<<endl;
  else
    cout<<"graph is not bipart"<<endl;
  return 0;
}

/*
3 3 // odd-length cyclic graph
0 1
1 2
2 0
graph is not bipart

4 4 // even-length cyclic graph
0 1
1 2
2 3
3 0
graph is bipart
*/