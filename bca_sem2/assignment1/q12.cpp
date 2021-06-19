#include <iostream>
using namespace std;

int main(){
  int a,b;
  cout<<"Enter 2 angles: ";
  cin>>a>>b;
  int c = 180 - (a+b);
  cout<<"3rd angle = "<<c<<endl;
  return 0;
}