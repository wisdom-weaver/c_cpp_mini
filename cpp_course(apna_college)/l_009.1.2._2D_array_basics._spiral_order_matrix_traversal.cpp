
#include <cmath>
#include <iostream>
using namespace std;

int main() {
  int m = 3, n = 3;
  // cout << "Enter dimentions: ";
  // cin >> m >> n;
  int ar[m][n];

  int cs = 0;
  int rs = 0;
  int re = n - 1;
  int ce = m - 1;

  int i = 0;
  while (i < m * n) {
    for (int lr = cs; lr <= ce && i < m * n; lr++)
      ar[rs][lr] = i++;
    rs++;

    for (int tb = rs; tb <= re && i < m * n; tb++)
      ar[tb][ce] = i++;
    ce--;

    for (int rl = ce; rl >= cs && i < m * n; rl--)
      ar[re][rl] = i++;
    re--;

    for (int bt = re; bt >= rs && i < m * n; bt--)
      ar[bt][cs] = i++;
    cs++;
  }

  cout << " matrix: " << endl;
  for (int i = 0; i < m; i++, cout << endl)
    for (int j = 0; j < n; j++)
      cout << ar[i][j] << "  ";

  return 0;
}
