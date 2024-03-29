#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string key_corr[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

void keypad(string s, string ans)
{
  if (s.length() == 0)
  {
    cout << ans << endl;
    return;
  }
  int n = s[0] - '0';
  string code = key_corr[n];
  string ros = s.substr(1);
  for (int i = 0; i < code.length(); i++)
    keypad(ros, ans + code[i]);
}

int main()
{
  keypad("23", "");
  return 0;
}
