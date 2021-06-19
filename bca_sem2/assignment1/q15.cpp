#include <iostream>
#include <cmath>
using namespace std;

int main(){
  float a;
  cout<<"Enter side of equilateral triangle: ";
  cin>>a;
  float area = 1.73*pow(a,2)/4;
  cout<<"area of triangle ="<< area<<endl;
  return 0;
}
