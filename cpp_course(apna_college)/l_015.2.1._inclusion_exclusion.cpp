#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

// eg: how many numbers b/w 1 and 1000 are divisible by 5 or 7

int divisible(int n, int a, int b)
{
  int c1 = n / a;
  int c2 = n / b;
  int c3 = n / (a * b);
  return c1 + c2 - c3;
}

int main()
{
  int n, a, b;
  cin >> n >> a >> b;
  cout << divisible(n, a, b) << endl;
  return 0;
}
