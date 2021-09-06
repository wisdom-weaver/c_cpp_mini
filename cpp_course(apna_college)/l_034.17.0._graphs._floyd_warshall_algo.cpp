#include <bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
const int I = 1e9; //infinity


int main(){
  vector<vector<int>> graph={
    {0, 5, I, 10},
    {I, 0, 3, I},
    {I, I, 0, 1},
    {I, I, I, 0},
  };

  vector<vector<int>> dist = graph;
  int n = graph.size();
  for(int k=0;k<n;k++)
    for(int i=0;i<n;i++)
      for(int j=0;j<n;j++)
        if(dist[i][j] > dist[i][k]+dist[k][j])
          dist[i][j] = dist[i][k]+dist[k][j];

  for(int i=0;i<n;i++, cout<<endl)
      for(int j=0;j<n;j++)
          if(dist[i][j]==I) cout<<"I ";
          else cout<<dist[i][j]<<" ";

  return 0;
}

/*
0 5 8 9 
I 0 3 4 
I I 0 1 
I I I 0 
*/