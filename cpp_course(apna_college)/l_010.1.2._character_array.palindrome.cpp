#include <iostream>
using namespace std;

bool check_palindrome(char ar[], int n)
{
  for (int i = 0; i < n / 2; i++)
    if (ar[i] != ar[n - i - 1])
      return false;
  return true;
}

int main()
{
  int n;
  cin >> n;
  char ar[n + 1];
  cin >> ar;
  cout << (check_palindrome(ar, n) ? "is" : "is not") << " a palindrome";
  return 0;
}