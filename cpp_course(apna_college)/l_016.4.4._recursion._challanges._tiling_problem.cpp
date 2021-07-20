#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

/*
  calculate the number of ways you can fill a board with tiles 
  board size => 2xn 
  tile size => 2x1 
*/

int tiling_ways(int n)
{
  if (n == 0)
    return 0;
  if (n == 1)
    return 1;
  int vert = tiling_ways(n - 1);
  int hori = tiling_ways(n - 2);
  return vert + hori;
}

int main()
{
  cout << tiling_ways(4);
  return 0;
}
