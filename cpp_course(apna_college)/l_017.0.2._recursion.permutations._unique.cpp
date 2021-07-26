#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

vector<vector<int>> ans;

void permute(vector<int> &a, int idx)
{
  if (idx == a.size())
  {
    ans.push_back(a);
    return;
  }
  for (int i = idx; i < a.size(); i++)
  {
    if (i != idx && a[i] == a[idx])
      continue;
    swap(a[i], a[idx]);
    permute(a, idx + 1);
    swap(a[idx], a[i]);
  }
  return;
}

int main()
{
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &i : a)
    cin >> i;
  permute(a, 0);
  for (auto v : ans)
  {
    for (auto i : v)
      cout << i << " ";
    cout << endl;
  }

  return 0;
}

// complexity O(N!)