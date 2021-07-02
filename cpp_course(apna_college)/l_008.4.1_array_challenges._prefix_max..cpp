// find max till i

#include <iostream>
using namespace std;

int main() {
  int n;
  cout << "Enter size: ";
  cin >> n;

  int ar[n];
  cout << "Enter elems: ";
  for (int i = 0; i < n; i++)
    cin >> ar[i];

  int i;
  cout << "Enter i: ";
  cin >> i;

  int mx = INT8_MIN;
  while (i--)
    mx = max(mx, ar[i]);

  cout << "max till i " << mx << endl;
}
