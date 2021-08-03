#include <iostream>
using namespace std;

void dnf_sort(int *arr, int n)
{
  int low = 0;
  int mid = 0;
  int high = n - 1;
  while (mid <= high)
  {
    if (arr[mid] == 0)
    {
      swap(arr[low], arr[mid]);
      low++;
      mid++;
    }

    else if (arr[mid] == 1)
    {
      mid++;
    }

    else if (arr[mid] == 2)
    {
      swap(arr[high], arr[mid]);
      high--;
    }
  }
}

int main()
{
  int n = 11;
  int arr[n] = {0, 1, 1, 2, 0, 0, 1, 2, 2, 1, 0};
  for (int i = 0; i < n; i++)
    cout << arr[i] << " ";
  cout << endl;

  dnf_sort(arr, n);

  for (int i = 0; i < n; i++)
    cout << arr[i] << " ";

  return 0;
}

// compexity O(n)