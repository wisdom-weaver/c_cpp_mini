#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

void subsets(int ar[], int n)
{
  for (int i = 0; i < 1 << n; i++, cout << endl)
    for (int j = 0; j < n; j++)
      if (i & (1 << j))
        cout << ar[j] << ", ";
}

int main()
{
  int ar[] = {1, 2, 3};
  int n = 3;
  subsets(ar, 3);
  return 0;
}