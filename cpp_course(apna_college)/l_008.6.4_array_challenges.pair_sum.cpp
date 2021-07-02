
#include <cmath>
#include <iostream>
using namespace std;

bool pairsum(int ar[], int n, int k) {
  int mapped[n] = {}, low = 0, high = n - 1, sum;
  while (low < high) {
    sum = ar[low] + ar[high];
    if (sum == k)
      return true;
    if (sum < k)
      low++;
    else
      high--;
  }

  return false;
}

int main() {
  int ar[] = {2, 4, 7, 11, 14, 16, 20, 21};
  int n = sizeof(ar) / sizeof(ar[0]);
  int k = 31;

  cout << pairsum(ar, n, k) << endl;
  return 0;
}
