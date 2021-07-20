#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int is_power_of_2(int n)
{
  // 8 = 1000
  // 7 = 0111
  // 1000 & 0111 == 0
  return n && (n & (n - 1)) == 0;
}

int main()
{
  cout << is_power_of_2(0) << endl;
  cout << is_power_of_2(5) << endl;
  cout << is_power_of_2(4) << endl;
  cout << is_power_of_2(8) << endl;
  cout << is_power_of_2(15) << endl;
  cout << is_power_of_2(16) << endl;
  return 0;
}