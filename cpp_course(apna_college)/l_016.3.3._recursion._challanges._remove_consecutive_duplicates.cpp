#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string remove_duplicates(string s)
{
  if (s.size() == 0)
    return "";
  string ans = remove_duplicates(s.substr(1));
  if (ans[0] == s[0])
    return ans;
  else
    return s[0] + ans;
}

int main()
{
  string s = "aabbccddeeffggggg";
  cout << remove_duplicates(s);
  return 0;
}
