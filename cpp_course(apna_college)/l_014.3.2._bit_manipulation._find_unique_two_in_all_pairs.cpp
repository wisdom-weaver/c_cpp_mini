#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int is_set_bit(int n, int pos)
{
  return (n & (1 << pos)) != 0;
}

void uniques_2(int ar[], int n)
{
  int xorsum = 0;
  for (int i = 0; i < n; i++)
    xorsum = xorsum ^ ar[i];

  int setbit = 0;
  int pos = 0;
  int t_xor = xorsum;
  while (setbit != 1)
  {
    setbit = t_xor & 1;
    pos++;
    t_xor = t_xor >> 1;
  }

  int a_xor = 0;
  for (int i = 0; i < n; i++)
    if (is_set_bit(ar[i], pos - 1))
      a_xor = a_xor ^ ar[i];

  int b_xor = xorsum ^ a_xor;
  cout << a_xor << endl;
  cout << b_xor << endl;
}

int main()
{
  int ar[] = {2, 4, 6, 7, 4, 5, 6, 2};
  int n = 8;
  uniques_2(ar, n);
  return 0;
}