#include <cmath>
#include <iostream>
using namespace std;

int main() {
  int ar[] = {1, 5, 3, 4, 3, 5, 6};
  int n = sizeof(ar) / sizeof(ar[0]);

  int N = 100;
  int flags[N] = {0}, min_idx = INT8_MAX;
  for (int i = 1; i < N; i++)
    flags[i] = -1;

  for (int i = 0; i < n; i++) {
    if (flags[ar[i]] != -1)
      min_idx = min(min_idx, flags[ar[i]]);
    else
      flags[ar[i]] = i;
  }

  if (min_idx != INT8_MAX)
    cout << ar[min_idx];
  else
    cout << "not found";
  cout << endl;
}
