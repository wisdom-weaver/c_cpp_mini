#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

void merge(int *arr, int l, int mid, int r)
{
  int n1 = mid - l + 1;
  int n2 = r - mid;
  int a[n1];
  int b[n2];

  for (int i = 0; i < n1; i++)
    a[i] = arr[l + i];
  for (int i = 0; i < n2; i++)
    b[i] = arr[mid + 1 + i];

  int i = 0, j = 0, k = l;
  while (i < n1 && j < n2)
    if (a[i] < b[j])
      arr[k++] = a[i++];
    else
      arr[k++] = b[j++];

  while (i < n1)
    arr[k++] = a[i++];
  while (j < n2)
    arr[k++] = b[j++];
}

void merge_sort(int *arr, int l, int r)
{
  if (l < r)
  {

    int mid = (l + r) / 2;
    merge_sort(arr, l, mid);
    merge_sort(arr, mid + 1, r);
    merge(arr, l, mid, r);
  }
}

int main()
{
  int n;
  cin >> n;
  int arr[n];
  for (int i = 0; i < n; i++)
    cin >> arr[i];

  // int n = 5;
  // int arr[n] = {3, 1, 2, 6, 5};

  merge_sort(arr, 0, n - 1);

  for (int i = 0; i < n; i++)
    cout << arr[i] << " ";

  return 0;
}

/*
Complexity => n * log n

5 
9 7 2 1 5
1 2 5 7 9 

*/