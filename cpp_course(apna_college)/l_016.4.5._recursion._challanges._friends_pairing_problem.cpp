#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int friends_paring(int n)
{
  if (n <= 2)
    return n;
  //since this person remains single so we are not concerned and proceed
  int to_single = friends_paring(n - 1) * 1;

  // since this person can be paired with others in n-1 ways
  // n-2 people remain to pair
  int to_pair = friends_paring(n - 2) * (n - 1);
  return to_pair + to_single;
}

int main()
{
  cout << friends_paring(4);
  return 0;
}
