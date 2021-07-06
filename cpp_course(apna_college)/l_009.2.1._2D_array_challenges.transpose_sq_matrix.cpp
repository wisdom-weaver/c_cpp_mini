
#include <cmath>
#include <iostream>
using namespace std;

int main() {
  int m = 3, n;
  cout << "Enter dimentions: ";
  cin >> m;
  n = m;
  int ar[m][n];
  cout << "Enter matrix: " << endl;
  for (int i = 0; i < m; i++)
    for (int j = 0; j < n; j++)
      cin >> ar[i][j];

  for (int i = 0; i < m; i++)
    for (int j = 0; j < i; j++)
      swap(ar[j][i], ar[i][j]);

  cout << " matrix: " << endl;
  for (int i = 0; i < m; i++, cout << endl)
    for (int j = 0; j < n; j++)
      cout << ar[i][j] << "  ";

  return 0;
}
