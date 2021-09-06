#include <bits/stdc++.h>
using namespace std;

int main(){

  int ladders, snakes;
  cin>>ladders;
  map<int,int> ladd;
  for(int i=0;i<ladders;i++){
    int u,v; cin>>u>>v;
    ladd[u]=v;
  }
  cin>>snakes;
  map<int,int> snak;
  for(int i=0;i<snakes;i++){
    int u,v; cin>>u>>v;
    snak[u]=v;
  }

  int moves=0;
  queue<int>q;
  bool found=false;
  vector<int> vis(101,0);

  q.push(1);
  vis[1]=1;

  while(!q.empty() && !found){
    int sz=q.size();
    while(sz--){
      int t = q.front(); q.pop();
      for(int die=1;die<=6;die++){
        if(t+die==100)
          found==true;
        if(t+die<=100 && ladd[t+die] && !vis[ladd[t+die]]){
          vis[ladd[t+die]]=true;
          if(ladd[t+die]==100) found==true;
          q.push(ladd[t+die]);
        }else if(t<=100 && snak[t+die] && !vis[snak[t+die]]){
          vis[snak[t+die]]=true;
          if(snak[t+die]==100) found=true;
          q.push(snak[t+die]);
        }else if(t<=100 && !vis[t+die] && !snak[t+die] && !ladd[t+die]){
          vis[t+die]=true;
          if(t+die==100) found=true;
          q.push(t+die);
        }
      }
    }
    moves++;
  }
  if(found) cout<<"moves: "<<moves;
  else cout<<"moves: "<<-1;
  return 0;
}

/*

2 // -> ladders
3 90
56 76
3 // -> snakes
99 10
30 20
20 5
moves: 3

*/