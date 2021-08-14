#include <bits/stdc++.h>
using namespace std;

int longest_substring_length_without_repeating_character(string s){
  vector<int> dict(256, -1);
  int max_len = 0, start = -1;
  for (int i = 0; i < s.size(); i++){
    if (dict[s[i]] > start)
      start = dict[s[i]];
    dict[s[i]] = i;
    max_len = max(max_len, i - start);
  }
  return max_len;
}

int main()
{

  string s = "abcdefjjjjjjjjj";
  // cin >> s;
  cout << s << endl;
  cout << "longest_substring_length_without_repeating_character ";
  cout << longest_substring_length_without_repeating_character(s) << endl;
  return 0;
}