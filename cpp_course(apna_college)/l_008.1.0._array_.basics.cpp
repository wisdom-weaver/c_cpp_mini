#include <iostream>
#include <cmath>
using namespace std;

int main() {
  int n;

  cout << "Enter size: ";
  cin >> n;
  int ar[n];

  cout << "Enter array elems: ";
  for (int i = 0; i < n; i++)
    cin >> ar[i];

  cout << "Array :";
  for (int i = 0; i < n; i++)
    cout << ar[i] << " ";
  cout << "\n";

  // find max
  int max_n = INT8_MIN, min_n = INT8_MAX;
  for (int i = 0; i < n; i++) {
    // if (ar[i] > max_n) max_n = ar[i]; // M-1
    max_n = max(max_n, ar[i]); // M-2

    // if (ar[i] < min_n) min_n = ar[i]; //M-1
    min_n = min(min_n, ar[i]); // M-2
  }
  cout << "min:" << min_n << endl;
  cout << "max:" << max_n << endl;
}