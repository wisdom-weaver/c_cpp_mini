#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int find_unique_in_pairs(int ar[], int n)
{
  int xorsum = 0;
  for (int i = 0; i < n; i++)
    xorsum = xorsum ^ ar[i];
  return xorsum;
}

int main()
{
  int ar[] = {2, 4, 6, 3, 4, 6, 2};
  int n = 7;
  int u = find_unique_in_pairs(ar, n);
  cout << u << endl;
  return 0;
}