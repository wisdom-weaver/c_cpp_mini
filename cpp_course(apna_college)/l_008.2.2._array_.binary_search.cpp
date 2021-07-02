#include <iostream>
using namespace std;

int binary_search(int ar[], int n, int key) {
  int beg = 0, last = n, mid;
  while (beg <= last) {
    mid = (beg + last) / 2;
    if(ar[mid]==key)
      return mid;
    else if (ar[mid] < key)
      beg = mid + 1;
    else if (ar[mid] > key)
      last = mid - 1;
  }
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

  for (int i = 0; i < n; i++)
    cout << ar[i];
  cout << endl;

  int key;
  cout << "Enter key: ";
  cin >> key;

  int idx = binary_search(ar, n, key);
  if (idx == -1)
    cout << "Element not found";
  else
    cout << "element found at " << idx;
  cout << "\n\n";
}

// time complexity: log(n)::base 2