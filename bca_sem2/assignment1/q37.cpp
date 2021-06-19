// Even odd

#include <iostream>
#include <cmath>
using namespace std;

int main(){
  int n;
  cout<<"Enter n: ";
  cin>>n;
  cout<<n<<" is "<<(n%2==0?"even":"odd")<<endl;
  return 0;
}
