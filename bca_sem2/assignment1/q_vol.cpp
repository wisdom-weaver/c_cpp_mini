// Write a program in C++ to calculate the volume of a cylinder.

#include <iostream>
#include <cmath>
using namespace std;
#define PI 3.14

int main(){
  float r, h;
  cout<<"Enter radius of cylinder: ";
  cin>>r;
  cout<<"Enter height of cylinder: ";
  cin>>h;
  float vol = PI*pow(r,2)*h;
  cout<<"volume: "<<vol<<" cubic units"<<endl;
  return 0;
}
