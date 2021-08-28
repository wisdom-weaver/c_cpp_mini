#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
const int N = 1e5+2;
vi adj[N];
bool vis[N];

void dfs(int node, string t){
  // preorder
  vis[node]=true;
  if(t=="inorder")
    cout<<node<<" ";
  // inorder
  vector<int>::iterator it;
  for(it=adj[node].begin(); it!=adj[node].end(); it++){
    if(vis[*it]);
    else{
      dfs(*it, t);
    }
  }

  // postorder
  if(t=="postorder")
    cout<<node<<" ";
}

int main(){

  int n,m; cin>>n>>m;
  int x,y, first_node;
  for(int i=0;i<m;i++){
    cin>>x>>y;
    if(i==0) first_node=x;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }

  for(int i=0;i<N;i++) vis[i]=0;
  string t = "inorder";
  cout<<t<<": "; dfs(first_node, t); cout<<endl;

  for(int i=0;i<N;i++) vis[i]=0;
  t = "postorder";
  cout<<t<<": "; dfs(first_node, t); cout<<endl;

  return 0;
}