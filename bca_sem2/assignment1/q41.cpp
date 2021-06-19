// max between 3 numbers

#include <iostream>
#include <cmath>
using namespace std;

int main(){
  int a, b, c;
  cout<<"Enter a b c: ";
  cin>>a>>b>>c;
  int lar;
  if(a>b) 
    if(a>c) lar = a;
    else lar = c; 
  else 
    if(b>c) lar = b;
    else lar = c;
  cout<<"largest: "<<lar<<endl;
  return 0;
}
