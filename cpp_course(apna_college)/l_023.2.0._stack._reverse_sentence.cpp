#include <iostream>
#include <stack>
using namespace std;

string reverse_sentence(string s)
{
  string s2 = "";
  stack<string> st;
  int pos = -1;
  for (int i = 0; i < s.length(); i++)
  {
    if (s[i] == ' ')
    {
      string word = s.substr(pos + 1, i - pos);
      st.push(word);
      pos = i;
    }
  }
  while (!st.empty())
  {
    s2 += st.top();
    st.pop();
  }
  return s2;
}

int main()
{
  string s = "Hey how are you doing";
  cout << "string:   " << s << endl;
  s = reverse_sentence(s);
  cout << "reversed: " << s << endl;
  return 0;
}
