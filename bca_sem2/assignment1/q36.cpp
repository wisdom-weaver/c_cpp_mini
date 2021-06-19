// Find max b/w 3 numbers

#include <iostream>
#include <cmath>
using namespace std;

int main(){
  int a,b,c;
  cout<<"Enter three numbers: ";
  cin>>a>>b>>c;
  int maxim = (a>b)? (a>c?a:c) : (b>c?b:c);
  cout<<"Maximum: "<< maxim<<endl;
  return 0;
}
