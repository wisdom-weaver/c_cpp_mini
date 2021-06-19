// leap year

#include <iostream>
#include <cmath>
using namespace std;

int main(){
  int n;
  cout<<"Enter year: ";
  cin>>n;
  cout<<n<<" is "<<((n%400==0 || ( n%4==0&&n%100==0))?"a":"not")<<"leap year"<<endl;
  return 0;
}
