//find smallest positive missing n from an array

#include <cmath>
#include <iostream>
using namespace std;

int main() {
  int ar[] = {0, 9, 1, 3, -4, 5};
  int n = sizeof(ar) / sizeof(ar[0]);

  int N = 1e6;
  int flags[N], it = N;
  while (it--)
    flags[it] = false;

  for (int i = 0; i < n; i++)
    if (ar[i] >= 0)
      flags[ar[i]] = true;

  for (int i = 1; i < N; i++)
    if (flags[i] == false) {
      cout << i;
      break;
    }

  cout << endl;
}
