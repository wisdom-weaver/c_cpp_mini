// max between 2 numbers

#include <iostream>
#include <cmath>
using namespace std;

int main(){
  int a, b;
  cout<<"Enter a and b: ";
  cin>>a>>b;
  int lar;
  if(a>b) lar = a;
  else lar = b;
  cout<<"largest: "<<lar<<endl;
  return 0;
}
