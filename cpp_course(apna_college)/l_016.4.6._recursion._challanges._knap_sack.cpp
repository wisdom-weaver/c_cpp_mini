#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int knap(int wt[], int val[], int n, int W)
{
  if (n == 0 || W == 0)
    return 0;
  if (wt[n - 1] > W)
    return knap(val, wt, n - 1, W);

  // considering you pick up this item the value is
  int v1 = knap(val, wt, n - 1, W - wt[n - 1]) + val[n - 1];
  // considering you dont pickup this item
  int v2 = knap(val, wt, n - 1, W);
  return max(v1, v2);
}

int main()
{
  int wt[] = {10, 20, 30};
  int val[] = {100, 50, 150};
  int n = 3;
  int W = 50;
  cout << knap(wt, val, n, W);
  return 0;
}
