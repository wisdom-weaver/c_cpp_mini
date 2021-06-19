#include <iostream>
using namespace std;
#define PI 3.14

int main(){
  float m, km;
  cout<<"Enter lenght in meter: ";
  cin>>m;
  km = 0.001*m;
  cout<<"\n> km: "<<km<<endl;

  return 0;
}