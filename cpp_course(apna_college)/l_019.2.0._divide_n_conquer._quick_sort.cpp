#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int a = 0;
int mx = 500;

void swap(int *arr, int i, int j)
{
  int temp = arr[i];
  arr[i] = arr[j];
  arr[j] = temp;
}

int partition(int *arr, int l, int r)
{
  int pivot = arr[r];
  int i = l - 1;
  for (int j = l; j < r; j++)
    if (arr[j] < pivot)
    {
      i++;
      swap(arr, i, j);
    }
  swap(arr, i + 1, r);
  return i + 1;
}

void quick_sort(int *arr, int l, int r)
{
  if (l < r)
  {
    int pi = partition(arr, l, r);
    quick_sort(arr, l, pi - 1);
    quick_sort(arr, pi + 1, r);
  }
}

int main()
{
  // int n;
  // cin >> n;
  // int arr[n];
  // for (int i = 0; i < n; i++)
  //   cin >> arr[i];

  int n = 2;
  // int arr[n] = {5, 4, 3, 2, 1};
  int arr[n] = {1, 2};

  quick_sort(arr, 0, n - 1);

  for (int i = 0; i < n; i++)
    cout << arr[i] << " ";

  return 0;
}

/*
best  case complexity => n * log n
worst case complexity => n^2

*/