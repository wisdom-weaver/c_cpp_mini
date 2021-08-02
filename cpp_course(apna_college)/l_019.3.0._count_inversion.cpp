#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

typedef long long ll;

// inversion means no of times a element has a smaller element after it 

ll merge(int *arr, int l, int mid, int r)
{
  int inv = 0;
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
    if (a[i] <= b[j])
      arr[k++] = a[i++];
    else
    {
      // this is case of inversion where a[i]>b[j]
      inv += n1 - i; // take into consideration elements after i idx in array a[]
      arr[k++] = b[j++];
    }

  while (i < n1)
    arr[k++] = a[i++];
  while (j < n2)
    arr[k++] = b[j++];
}

ll merge_sort(int *arr, int l, int r)
{
  int inv = 0;
  if (l < r)
  {
    int mid = (l + r) / 2;
    inv += merge_sort(arr, l, mid);
    inv += merge_sort(arr, mid + 1, r);
    inv += merge(arr, l, mid, r);
  }
  return inv;
}

int main()
{
  // int n;
  // cin >> n;
  // int arr[n];
  // for (int i = 0; i < n; i++)
  //   cin >> arr[i];

  int n = 8;
  int arr[n] = {3, 5, 6, 9, 1, 2, 7, 8};
  for (int i = 0; i < n; i++)
    cout << arr[i] << " ";
  cout << endl;

  ll inv = merge_sort(arr, 0, n - 1);
  for (int i = 0; i < n; i++)
    cout << arr[i] << " ";
  cout << endl;
  cout << "inversions: " << inv << endl;

  return 0;
}