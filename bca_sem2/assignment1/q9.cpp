#include <iostream>
using namespace std;

int main(){
  float f;
  cout<<"Enter temp in F: ";
  cin>>f;
  float c = (f-32.0)*(100.0/180.0);
  cout<<"temp in celcius: "<<c<<endl;
  return 0;
}