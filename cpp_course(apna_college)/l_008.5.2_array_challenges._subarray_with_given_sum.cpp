#include <cmath>
#include <iostream>
using namespace std;

int main() {
  int ar[] = {1, 1, 1, 3, 4, 3, 5, 6};
  int n = sizeof(ar) / sizeof(ar[0]);
  int req_sum = 6;

  // M-1: Brute Force - by subarrays sum method
  // int sum, s = -1, e = -1;
  // for (int i = 0; i < n; i++) {
  //   int j = i;
  //   sum = 0;
  //   while (j--) {
  //     sum += ar[j];
  //     if (sum == req_sum) {
  //       s = j;
  //       e = i;
  //       goto got;
  //     } else if (sum > req_sum) {
  //       break;
  //     }
  //   }
  // }

  // M-2: Efficient
  int curr_sum = ar[0], s = 0, e = 0;
  for (int i = 1; i < n; i++) {

    // remove elems from start if current sum excedes
    while (curr_sum > req_sum && s < i - 1)
      curr_sum -= ar[s++];

    if (curr_sum == req_sum) {
      // terminate if you find the 
      e = i - 1;
      goto got;
    } else
      // add elems to the end 
      curr_sum += ar[i]; 
  }

got:
  cout << s << " : " << e << endl;
  for (int i = s; i <= e; i++)
    cout << ar[i] << " ";
  cout << endl;
}
