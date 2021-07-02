// arithematic array is an array such that differences between consecutive elems are equal
// like AP
// min length: 2

// find the longest contiguous arithemtic sub array

#include <cmath>
#include <iostream>
using namespace std;

int main() {
  int ar[] = {1, 2, 2, 2, 2, 2, 0, 7, 7, 2, 2};
  int n = sizeof(ar) / sizeof(ar[0]);

  int pd = ar[0] - ar[1];
  int curr = 2, len = 2;
  for (int i = 1; i < n; i++) {
    if (pd == ar[i] - ar[i - 1])
      ++curr;
    else {
      pd = ar[i] - ar[i - 1];
      curr = 2;
    }
    len = max(curr, len);
  }

  cout << endl;
  cout << len << endl;
}
