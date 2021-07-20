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

int clear_bit(int n, int pos)
{
  return (n & ~(1 << pos));
}

int update_bit(int n, int pos, int a)
{
  //clear bit at pos first
  n = n & ~(1 << pos);
  //set bit at pos now
  n = n | a << pos;
  return n;
}

int main()
{
  cout << get_bit(0b0101, 2) << endl;
  cout << set_bit(0b0101, 1) << endl;
  cout << clear_bit(0b0101, 0) << endl;
  cout << update_bit(0b0101, 3, 1) << endl;
  cout << update_bit(0b0101, 3, 0) << endl;
  return 0;
}