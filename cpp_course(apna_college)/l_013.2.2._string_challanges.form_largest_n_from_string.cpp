#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
  string s = "829347";
  cout << s << endl;
  sort(s.begin(), s.end(), greater<int>());
  cout << s << endl;

  return 0;
}