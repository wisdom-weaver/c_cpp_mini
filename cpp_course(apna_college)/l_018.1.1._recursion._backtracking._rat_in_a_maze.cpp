#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

// maze from 0,0 to n,n
 
bool isSafe(int **ar, int x, int y, int n)
{
  if (x < n && y < n && ar[x][y] != 0)
    return true;
  return false;
}

bool rat_in_maze(int **ar, int x, int y, int n, int **sol_ar)
{
  if (x == n - 1 && y == n - 1)
  {
    sol_ar[x][y] = 1;
    return true;
  }
  if (isSafe(ar, x, y, n))
  {
    sol_ar[x][y] = 1;
    // move right
    if (rat_in_maze(ar, x + 1, y, n, sol_ar))
      return true;
    // move down
    if (rat_in_maze(ar, x, y + 1, n, sol_ar))
      return true;
    // move left
    sol_ar[x][y] = 0;
    return false;
  }
  return false;
}

int main()
{
  int n;
  cin >> n;
  int **ar = new int *[n];
  for (int i = 0; i < n; i++)
  {
    ar[i] = new int[n];
  }
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      cin >> ar[i][j];

  int **sol_ar = new int *[n];
  for (int i = 0; i < n; i++)
  {
    sol_ar[i] = new int[n];
  }
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      sol_ar[i][j] = 0;

  if (rat_in_maze(ar, 0, 0, n, sol_ar))
  {
    cout << "\n----\nfound way out of maze\n";
    for (int i = 0; i < n; i++, cout << endl)
      for (int j = 0; j < n; j++)
        cout << sol_ar[i][j] << " ";
  }
  else
    cout << "no way out of maze";

  return 0;
}

// complexity O(N!)

/*
input
5
1 0 1 0 1
1 1 1 1 1
0 1 0 1 0
1 0 0 1 1
1 1 1 0 1

*/