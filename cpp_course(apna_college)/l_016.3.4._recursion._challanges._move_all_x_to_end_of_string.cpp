#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string move_x_to_end(string s)
{
  if (s.size() == 0)
    return "";
  string ans = move_x_to_end(s.substr(1));
  if (s[0] == 'x')
    return ans + 'x';
  else
    return s[0] + ans;
}

int main()
{
  string s = "aabxxbxccxddxeefxfggxggg";
  cout << move_x_to_end(s);
  return 0;
}
