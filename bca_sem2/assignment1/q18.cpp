#include <iostream>
#include <cmath>
using namespace std;

int main(){
  float p,r,t;
  cout<<"Enter P(principal amt) R(rate) and T(time): ";
  cin>>p>>r>>t;
  float a = p*pow((1+r/100.0),t);
  float ci = a-p;
  cout<<"compound interest = "<<ci<<endl;
  cout<<"final amount = "<<a<<endl;
  return 0;
}
