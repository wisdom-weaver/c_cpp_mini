#include <iostream>
using namespace std;

void insertion_sort(int ar[], int n) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n - i; j++)
      if (ar[j] > ar[j + 1])
        swap(ar[j], ar[j + 1]);
  }
}

int main() {
  int n;
  cout << "Enter size: ";
  cin >> n;

  int ar[n];
  cout << "Enter elems: ";
  for (int i = 0; i < n; i++)
    cin >> ar[i];

  insertion_sort(ar, n);

  for (int i = 0; i < n; i++)
    cout << ar[i] << " ";
  cout << endl;
}

// time complexity: n^2