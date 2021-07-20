#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int first_occ(int ar[], int n, int i, int k)
{
  if (i == n)
    return -1;
  if (ar[i] == k)
    return i;
  return first_occ(ar, n, i + 1, k);
}

int last_occ(int ar[], int n, int i, int k)
{
  if (i == n)
    return -1;
  int rest = last_occ(ar, n, i + 1, k);
  if (rest != -1)
    return rest;
  if (ar[i] == k)
    return i;
  return -1;
}

int main()
{
  int ar[] = {4, 2, 1, 2, 5, 2, 7};
  int n = 7;
  cout << "first: " << first_occ(ar, n, 0, 2) << endl;
  cout << "last : " << last_occ(ar, n, 0, 2) << endl;
  return 0;
}
