#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int count_path_2d(int n, int i, int j)
{
  if (i == n - 1 && j == n - 1)
    return 1;
  if (i >= n || j >= n)
    return 0;
  return count_path_2d(n, i + 1, j) + count_path_2d(n, i, j + 1);
}

int main()
{
  cout << count_path_2d(3, 0, 0);
  return 0;
}
