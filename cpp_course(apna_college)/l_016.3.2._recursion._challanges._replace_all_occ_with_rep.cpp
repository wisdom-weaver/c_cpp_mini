#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string replace(string s, string key, string rep)
{
  if (s.size() == 0)
    return "";
  if (s.find(key) == 0)
    return rep + replace(s.substr(key.size()), key, rep);
  else
    return s[0] + replace(s.substr(1), key, rep);
}

int main()
{
  string s1 = "Danish";
  string key = "an";
  string rep = "AT";
  string s2 = replace(s1, key, rep);

  cout << s1 << endl;
  cout << s2 << endl;
  return 0;
}
