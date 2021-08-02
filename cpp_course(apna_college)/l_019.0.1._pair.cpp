#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool sorting_comparator(pair<int, int> p1, pair<int, int> p2)
{
  return p1.first < p2.first;
}

int main()
{
  pair<int, char> p;
  p.first = 3;
  p.second = 'A';
  cout << p.first << "::" << p.second << endl;
  cout << "---------\n\n";

  int arr[] = {10, 16, 7, 14, 5, 3, 2, 9};
  int n = sizeof(arr) / sizeof(arr[0]);
  
  vector<pair<int, int>> v;
  for (int i = 0; i < n; i++)
    v.push_back(make_pair(arr[i], i));

  sort(v.begin(), v.end(), sorting_comparator);
  for (int i = 0; i < v.size(); i++)
    arr[v[i].second] = i;
  for (int i = 0; i < n; i++)
    cout << arr[i] << " ";

  return 0;
}