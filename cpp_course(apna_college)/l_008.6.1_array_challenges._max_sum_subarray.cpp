
#include <cmath>
#include <iostream>
using namespace std;

int main() {
  int ar[] = {0, 9, 1, 3, -4, 5};
  int n = sizeof(ar) / sizeof(ar[0]);

  int sum_ar[n], sum = 0;
  for (int i = 0; i < n; i++)
    sum_ar[i] = sum += ar[i];

  int mx = INT8_MIN, s, e;
  for (int i = 1; i < n; i++) {
    int sum = 0;
    for (int j = i - 1; j >= 0; j--) {
      // cout << i << " : " << j << " " << sum_ar[i] - sum_ar[j] << endl;
      sum = sum_ar[i] - sum_ar[j];
      if (mx < sum) {
        mx = sum;
        s = j;
        e = i;
      }
    }
  }

  for (int i = s; i <= e; i++) {
    cout << ar[i] << " ";
  }

  cout << endl;
  cout << sum_ar[e] - sum_ar[s] << endl;
  return 0;
}
