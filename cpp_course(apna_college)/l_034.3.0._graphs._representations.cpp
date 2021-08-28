#include <bits/stdc++.h>
using namespace std;

#define ff first 
#define ss second
#define setBits(x)  builtin_popcount(x)
#define vi vector<int>
#define vvi vector<vector<int>>
#define pii pair<int,int>
#define rep(i,a,b) for(int i=a; i<b; i++)

const int N = 1e5+2;
const int MOD = 1e9+7;

vi adj[N];

int main(){
  // n=nodes m=edges
  int n,m; cin>>n>>m;
  
  // adjacency matrix
  vvi adj_m(n+1, vi(n+1,0));
  rep(i,0,m){
    int x,y; cin>>x>>y;
    adj_m[x][y] = 1;
    adj_m[y][x] = 1;
  }

  cout<<"adjacency matrix of above graph is given by"<<endl;
  rep(i,1,n+1){
    rep(j,1,n+1)
      cout<<adj_m[i][j]<<" ";
    cout<<endl;
  }

  // if(adj_m[3][7]==1)
  //   cout<<"there is an edge b/w 3 and 7\n";
  // else 
  //   cout<<"there no edge b/w 3 and 7\n";

  // adjacency list
  cin>>n>>m;
  rep(i,0,m){
    int x,y; cin>>x>>y;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }
  cout<<"\nadjacency matrix\n";
  rep(i,0,N){
    if(adj[i].size()<=0)continue;
      cout<<i<<"-> ";
      rep(j,0,adj[i].size())
        cout<<adj[i][j]<<" ";
      cout<<endl;
  }

  return 0;
}