#include <iostream>
using namespace std;

int linear_search(int *ar, int n, int key) {
  // int n = sizeof(ar) / sizeof(ar[0]);
  cout << n;
  for (int i = 0; i < n; i++)
    if (ar[i] == key)
      return i;
  return -1;
}

int main() {
  int n;
  cout << "Enter size: ";
  cin >> n;

  int ar[n];
  cout << "Enter elems: ";
  for (int i = 0; i < n; i++)
    cin >> ar[i];

  int key;
  cout << "Enter key: ";
  cin >> key;

  int idx = linear_search(ar, n, key);
  if (idx == -1)
    cout << "Element not found";
  else
    cout << "element found at " << idx;
  cout << "\n\n";
}