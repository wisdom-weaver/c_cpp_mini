//matrix is sorted rowwise and column wise
//search for k in the given matrix
#include <cmath>
#include <iostream>
using namespace std;

int main()
{
  int n1, n2;
  cout << "Enter n1, n2: ";
  cin >> n1 >> n2;
  int ar1[n1][n2];
  int k ;
  cout << "Enter key: ";
  cin >> k;

  cout << "Enter matrix1: " << endl;
  for (int i = 0; i < n1; i++)
    for (int j = 0; j < n2; j++)
      cin >> ar1[i][j];

  int flag = 0, r=0, c=n2-1;
  while(r!=n1 || c!=-1){
    if(ar1[r][c]==k){flag=1; break;}
    if(k<ar1[r][c]) c--;
    else r++;
  }

  if(flag==1)
    cout<<"found at "<<r<<","<<c;
  else 
    cout<<"not found";


  return 0;
}
