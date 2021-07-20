#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool check_sorted(int ar[], int n)
{
  if (n == 0)
    return 1;
  return ar[n - 1] < ar[n] && check_sorted(ar, n - 1);
}

int main()
{
  int ar[] = {0, 2, 3, 4, 7, 9};
  int n = 6;
  cout << "\n";
  cout << (check_sorted(ar, n) ? "sorted" : "not sorted") << endl;
  return 0;
}
