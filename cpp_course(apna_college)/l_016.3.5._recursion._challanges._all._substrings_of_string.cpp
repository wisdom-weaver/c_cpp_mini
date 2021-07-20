#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

void sub_seq(string s, string ans)
{
  if (s.size() == 0)
  {
    cout << ans << endl;
    return;
  }
  char ch = s[0];
  string ros = s.substr(1);

  sub_seq(ros, ans);
  sub_seq(ros, ans + ch);
}

void sub_seq_ascii(string s, string ans)
{
  if (s.size() == 0)
  {
    cout << ans << endl;
    return;
  }
  char ch = s[0];
  int code = (int)ch;
  string ros = s.substr(1);

  sub_seq_ascii(ros, ans);
  sub_seq_ascii(ros, ans + ch);
  sub_seq_ascii(ros, ans + to_string(code));
}

int main()
{
  string s = "AB";
  // sub_seq(s, "");
  sub_seq_ascii(s, "");
  return 0;
}
