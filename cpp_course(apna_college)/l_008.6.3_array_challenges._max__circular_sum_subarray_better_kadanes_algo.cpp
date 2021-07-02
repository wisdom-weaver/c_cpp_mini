
#include <cmath>
#include <iostream>
using namespace std;

int kadane(int ar[], int n) {
  int curr_sum_ar[n] = {ar[0]}, sum = 0, mx = INT8_MIN;
  for (int i = 1; i < n; i++) {
    curr_sum_ar[i] += curr_sum_ar[i - 1] + ar[i];
    if (curr_sum_ar[i] < 0)
      curr_sum_ar[i] = 0;
    mx = max(mx, curr_sum_ar[i]);
  }
  return mx;
}

int main() {
  int ar[] = {0, 9, 1, 3, -4, 5};
  int n = sizeof(ar) / sizeof(ar[0]);

  int wrapsum, nonwrapsum, totalsum;

  nonwrapsum = kadane(ar, n);

  // get total sum of array and also turn the array -ve;
  for (int i = 0; i < n; i++) {
    totalsum += ar[i];
    ar[i] = -ar[i];
  }

  wrapsum = totalsum - (-kadane(ar, n));

  cout << max(wrapsum, nonwrapsum) << endl;
  return 0;
}
