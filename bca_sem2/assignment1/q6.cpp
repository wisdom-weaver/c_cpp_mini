#include <iostream>
using namespace std;
#define PI 3.14

int main(){
  float r, d, cir, area;
  cout<<"Enter radius: ";
  cin>>r;
  d = 2*r;
  cir = 2*PI*r;
  area = PI*r*r;
  cout<<"\n> diameter: "<<d;
  cout<<"\n> cirumference: "<<cir;
  cout<<"\n> area: "<<area<<endl;

  return 0;
}