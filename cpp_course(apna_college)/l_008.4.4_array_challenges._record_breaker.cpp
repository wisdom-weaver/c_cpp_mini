#include <cmath>
#include <iostream>
using namespace std;

int main() {
  int ar[] = {1, 2, 0, 7, 2, 0, 2, 2};
  int n = sizeof(ar) / sizeof(ar[0]);

  int len = 1, mx = ar[0];
  for (int i = 1; i < n; i++) {
    if (ar[i] > mx && (i == n - 1 || mx > ar[i + 1])) {
      mx = ar[i];
      len++;
    }
  }

  cout << len << endl;
  cout << endl;
}
