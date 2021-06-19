#include <iostream>
#include <cmath>
using namespace std;

int main(){
  float p,r,t;
  cout<<"Enter P(principal amt) R(rate) and T(time): ";
  cin>>p>>r>>t;
  float si = p*r*t/100.0;
  cout<<"simple interest = "<<si<<endl;
  float a = p+si;
  cout<<"final amount = "<<a<<endl;
  return 0;
}