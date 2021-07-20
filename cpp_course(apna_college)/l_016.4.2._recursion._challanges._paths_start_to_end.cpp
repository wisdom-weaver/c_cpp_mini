#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int count_path(int s, int e)
{
  if (s == e)
    return 1;
  if (s > e)
    return 0;
  int c = 0;
  for (int i = 1; i <= 6; i++)
    c += count_path(s + i, e);
  return c;
}

int main()
{
  cout << count_path(0, 3);
  return 0;
}
