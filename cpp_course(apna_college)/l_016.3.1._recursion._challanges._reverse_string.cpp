#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string rev_string(string s)
{
  if (s.size() == 0)
    return "";
  return rev_string(s.substr(1))+s[0];
}

int main()
{
  string s1 = "Danish";
  string s2 = rev_string(s1);

  cout << s1 << endl;
  cout << s2 << endl;
  return 0;
}
