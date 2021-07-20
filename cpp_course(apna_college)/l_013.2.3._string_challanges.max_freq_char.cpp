#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
  string s = "nviousdjbnviubdsskdksdkskdss";
  int N = 26;
  int fqs[N];

  int n = N;
  while (n--)
    fqs[n] = 0;

  for (int i = 0; i < s.size(); i++)
    fqs[s[i] - 'a']++;

  int max_idx = 0;
  for (int i = 0; i < 26; i++)
    if (fqs[i] > fqs[max_idx])
      max_idx = i;
  cout << "max: " << (char)('a' + max_idx) << " => " << fqs[max_idx] << "" << endl;
  // sort(s.begin(), s.end());
  // cout << s;
  return 0;
}