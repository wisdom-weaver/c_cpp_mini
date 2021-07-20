#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int nof_1s_in_binary(int n)
{
  int c = 0;
  while (n)
  {
    n = n & (n - 1);
    c++;
  }
  return c++;
}

int main()
{
  cout << nof_1s_in_binary(0b01110010) << endl;
  return 0;
}