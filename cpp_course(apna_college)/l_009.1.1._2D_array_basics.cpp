
#include <cmath>
#include <iostream>
using namespace std;

int main() {
  int m, n;
  cout << "Enter dimentions: ";
  cin >> m >> n;
  int ar[m][n];

  cout << "Enter matrix: " << endl;
  for (int i = 0; i < m; i++)
    for (int j = 0; j < n; j++)
      cin >> ar[i][j];

  cout << " matrix: " << endl;
  for (int i = 0; i < m; i++, cout << endl)
    for (int j = 0; j < n; j++)
      cout << ar[i][j] << "  ";

  int key, flag = 0;
  cout << "Enter key: ";
  cin >> key;
  for (int i = 0; i < m; i++)
    for (int j = 0; j < n; j++)
      if (ar[i][j] == key) {
        cout << "found at " << i << ", " << j << endl;
        flag = 1;
      }

  if (flag == 0)
    cout << "elem not found";
  return 0;
}
