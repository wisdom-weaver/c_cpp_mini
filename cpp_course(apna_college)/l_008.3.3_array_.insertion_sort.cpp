#include <iostream>
using namespace std;

void insertion_sort(int ar[], int n) {
  for (int i = 1; i < n; i++) {
    int curr = ar[i];
    int j;
    for (j = i - 1; ar[j] > curr && j >= 0; j--)
      ar[j + 1] = ar[j];
    ar[j + 1] = curr;
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