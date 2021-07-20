#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int sum(int n)
{
  if (n == 0)
    return 0;
  return n + sum(n - 1);
}

int raised_to_power(int n, int p)
{
  if (p == 0)
    return 1;
  return n * raised_to_power(n, p - 1);
}

int factorial(int n)
{
  if (n == 0)
    return 1;
  return n * factorial(n - 1);
}

int fibinacci_nth(int n)
{
  if (n <= 1)
    return n;
  return fibinacci_nth(n - 1) + fibinacci_nth(n - 2);
}

int main()
{
  cout << sum(10) << endl;
  cout << raised_to_power(2, 6) << endl;
  cout << factorial(5) << endl;
  cout << fibinacci_nth(2) << endl;
  return 0;
}
