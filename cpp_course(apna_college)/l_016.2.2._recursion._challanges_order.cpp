#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

void dec(int n)
{
  if (n == 0)
    return;
  cout << n << endl;
  dec(n - 1);
}

void inc(int n)
{
  if (n == 0)
    return;
  inc(n - 1);
  cout << n << endl;
}

int main()
{
  int n = 4;
  dec(n);
  cout << "\n-----\n";
  inc(n);
  return 0;
}
