#include <iostream>
using namespace std;

// an element is lesser than its neighbouring elems
void wave_sort(int *arr, int n)
{
  for (int i = 0; i < n - 1; i += 2)
  {
    if (arr[i] > arr[i - 1])
      swap(arr[i], arr[i - 1]);
    if (arr[i] > arr[i + 1] && i < n - 1)
      swap(arr[i], arr[i + 1]);
  }
}

int main()
{
  int n = 11;
  int arr[n] = {0, 1, 1, 2, 0, 0, 1, 2, 2, 1, 0};
  for (int i = 0; i < n; i++)
    cout << arr[i] << " ";
  cout << endl;

  wave_sort(arr, n);

  for (int i = 0; i < n; i++)
    cout << arr[i] << " ";

  return 0;
}

// compexity O(n)