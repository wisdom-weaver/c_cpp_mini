#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int get_gcd_rec(int a, int b)
{
  if (a % b == 0)
    return b;
  return get_gcd_rec(b, a % b);
}

int get_gcd(int a, int b)
{
  while (b != 0)
  {
    int rem = a % b;
    a = b;
    b = rem;
  }
  return a;
}

int main()
{
  int a, b;
  cin >> a >> b;
  cout << get_gcd(a, b) << endl;
  return 0;
}
