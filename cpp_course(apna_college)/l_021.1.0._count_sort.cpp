#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

void count_sort(int *arr, int n)
{
  int mx = 0;
  for (int i = 0; i < n; i++)
    mx = max(mx, arr[i]);

  // make freq array
  int c_ar[mx + 1] = {0};
  for (int i = 0; i < n; i++)
    c_ar[arr[i]] += 1;

  // make cumulative freq
  for (int i = 1; i < n; i++)
    c_ar[i] += c_ar[i - 1];

  int output[n];
  for (int i = n - 1; i >= 0; i--)
    output[--c_ar[arr[i]]] = arr[i];
  for (int i = 0; i < n; i++)
    arr[i] = output[i];
}

int main()
{
  int n = 10;
  int arr[n] = {5, 4, 3, 2, 1, 5, 4, 1, 1, 3};
  for (int i = 0; i < n; i++)
    cout << arr[i] << " ";
  cout << endl;

  count_sort(arr, n);

  for (int i = 0; i < n; i++)
    cout << arr[i] << " ";

  return 0;
}

// compexity O(Ai, n)