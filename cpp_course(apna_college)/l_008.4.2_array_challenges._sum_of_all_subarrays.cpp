// given an arrray a[] of size n. Output sum of each subarray of the given array

#include <iostream>
using namespace std;

int main() {
  int ar[] = {1, 2, 0, 7, 2};
  int n = sizeof(ar) / sizeof(ar[0]);

  // number of subarray formed for array of size n => nC2 + n;

  for (int i = 0; i < n; i++) {
    int sum = 0;
    for (int j = 0; j <= i; j++)
      cout << (sum += ar[j], sum) << " ";
  }

  cout << endl;
}
