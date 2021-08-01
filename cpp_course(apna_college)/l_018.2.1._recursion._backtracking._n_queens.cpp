#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool is_safe(int **arr, int x, int y, int n)
{
  for (int row = 0; row < x; row++)
    if (arr[row][y] == 1)
      return false;
  for (int row = x, col = y; row >= 0 && col >= 0; row--, col--)
    if (arr[row][col] == 1)
      return false;
  for (int row = x, col = y; row >= 0 && col < n; row--, col++)
    if (arr[row][col] == 1)
      return false;
  return true;
}

bool n_queen(int **arr, int x, int n)
{
  if (x >= n)
    return true;
  for (int col = 0; col < n; col++)
    if (is_safe(arr, x, col, n))
    {
      arr[x][col] = 1;
      if (n_queen(arr, x + 1, n))
        return true;
      arr[x][col] = 0;
    }
  return false;
}

int main()
{
  int n;
  cin >> n;
  int **arr = new int *[n];
  for (int i = 0; i < n; i++)
  {
    arr[i] = new int[n];
    for (int j = 0; j < n; j++)
      arr[i][j] = 0;
  }

  if (n_queen(arr, 0, n))
  {
    cout << "n queens arranged\n";
    for (int i = 0; i < n; i++, cout << endl)
      for (int j = 0; j < n; j++)
        cout << arr[i][j] << " ";
  }
  else
    cout << "n queens couldnot be arranged";

  return 0;
}