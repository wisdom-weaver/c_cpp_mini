// negative zero positive

#include <iostream>
#include <cmath>
using namespace std;

int main(){
  int n;
  cout << "Enter n: ";
  cin >> n;
  int lar;
  if (n == 0)
    cout << n << " is zero" << endl;
  else if (n < 0)
    cout << n << " is negative" << endl;
  if (n > 0)
    cout << n << " is positive" << endl;
  return 0;
}
