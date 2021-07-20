#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
  // string str;
  // cin >> str;
  // cout << str;

  // getline(cin, str);
  // cout << str;

  // string s2(5, 'n');
  // cout << s2 << endl;

  // string s1 = "fam";
  // string s2 = "ily";
  // s1.append(s2);
  // cout<<s1;

  // string s3 = s1 + s2;
  // string s3 = s1 + s2;
  // cout << "s3: " << s3 << endl;
  // s3.clear();
  // cout << "s3: " << s3 << endl;

  string s1 = "abcdef";
  string s2 = "xyzabc";
  cout << s2.compare(s1) << endl; // lexiogrphical comparision
  cout << s2.empty() << endl;     // string is empty

  s1.erase(3, 2);
  cout << s1 << endl;
  cout << s2.find("abc") << endl;
  cout << s2.insert(3, "hey") << endl;
  cout << s2.size() << endl;
  cout << s2.length() << endl;
  cout << s2.substr(2, 1) << endl; // start idx, no of chars needed after start

  string s4 = "404";
  int x = stoi(s4);
  cout << x << endl;

  string s5 = to_string(x);
  cout << s5 << endl;

  string s6 = "ajkdshfaiubvaerbgkjsgh";
  sort(s6.begin(), s6.end());
  cout << s6;

  return 0;
}