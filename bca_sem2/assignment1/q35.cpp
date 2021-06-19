// Find max b/w 2 numbers

#include <iostream>
#include <cmath>
using namespace std;

int main(){
  int a,b;
  cout<<"Enter two numbers: ";
  cin>>a>>b;
  int maxim = a>b? a : b;
  cout<<"Maximum: "<< maxim<<endl;
  return 0;
}
