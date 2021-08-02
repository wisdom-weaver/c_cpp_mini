#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
  vector<int> v;
  v.push_back(1);
  v.push_back(2);
  v.push_back(3);
  v.push_back(4);
  for (int i = 0; i < v.size(); i++)
    cout << v[i] << " "; // 1 2 3
  cout << endl;

  vector<int>::iterator it;
  for (it = v.begin(); it != v.end(); it++)
    cout << *it << " "; // 1 2 3
  cout << endl;

  v.pop_back();

  for (auto el : v)
    cout << el << " "; // 1 2
  cout << endl;

  vector<int> v2(3, 50); // 50 50 50

  swap(v, v2);
  for (auto el : v)
    cout << el << " "; // 50 50 50
  cout << endl;
  for (auto el : v2)
    cout << el << " "; // 1 2 3
  cout << endl;

  vector<int> v3(3);
  for (auto &i : v3)
    cin >> i;
  for (auto i : v3)
    cout << i << " ";
  cout << endl;
  sort(v3.begin(), v3.end());
  for (auto i : v3)
    cout << i << " ";
  cout << endl;

  return 0;
}