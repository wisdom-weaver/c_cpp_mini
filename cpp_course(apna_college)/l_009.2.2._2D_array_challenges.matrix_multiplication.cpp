
#include <cmath>
#include <iostream>
using namespace std;

int main()
{
  int n1, n2, n3;
  cout << "Enter n1, n2, n3: ";
  cin >> n1 >> n2 >> n3;
  int ar1[n1][n2];
  int ar2[n2][n3];
  int ar3[n1][n3];

  cout << "Enter matrix1: " << endl;
  for (int i = 0; i < n1; i++)
    for (int j = 0; j < n2; j++)
      cin >> ar1[i][j];
  cout << "Enter matrix2: " << endl;
  for (int i = 0; i < n2; i++)
    for (int j = 0; j < n3; j++)
      cin >> ar2[i][j];

  cout << " matrix 1: " << endl;
  for (int i = 0; i < n1; i++, cout << endl)
    for (int j = 0; j < n2; j++)
      cout << ar1[i][j] << "  ";
  cout << " matrix 2: " << endl;
  for (int i = 0; i < n1; i++, cout << endl)
    for (int j = 0; j < n2; j++)
      cout << ar1[i][j] << "  ";

  for (int i = 0; i < n1; i++)
  {
    for (int j = 0; j < n3; j++)
    {
      int sum = 0;
      for (int k = 0; k < n2; k++)
        sum += ar1[i][k] * ar2[k][j];
      ar3[i][j] = sum;
    }
  }

  cout << "Resultant matrix: " << endl;
  for (int i = 0; i < n1; i++, cout << endl)
    for (int j = 0; j < n3; j++)
      cout << ar3[i][j] << "  ";

  return 0;
}
