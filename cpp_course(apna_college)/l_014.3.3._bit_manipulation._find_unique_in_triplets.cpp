#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int get_bit(int n, int pos)
{
  return (n & (1 << pos)) != 0;
}
int set_bit(int n, int pos)
{
  return (n | (1 << pos));
}

int unique_in_triplets(int ar[], int n)
{
  int result = 0;
  for (int i = 0; i <= 63; i++)
  {
    int sum = 0;
    for (int j = 0; j < n; j++)
      if (get_bit(ar[j], i))
        sum++;
    if (sum % 3 != 0)
      result = set_bit(result, i);
  }
  return result;
}

int main()
{
  int ar[] = {1, 2, 3, 4, 1, 2, 3, 1, 2, 3};
  int n = 10;
  cout << unique_in_triplets(ar, n);
  return 0;
}

// https://www.youtube.com/watch?v=WEpLyOc0bCE&list=PLfqMhTWNBTe0b2nM6JHVCnAkhQRGiZMSJ&index=35