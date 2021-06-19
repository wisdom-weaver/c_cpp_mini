#include <iostream>
using namespace std;

int is_prime(int n){
  for(int i=2; i<n/2; i++)
    if(n%i==2) return 0;
  return 1;
}

int main(){
  cout<<"Enter n: ";
  int n; cin>>n;
  if(is_prime(n)) cout<<n<<" is prime";
  else cout<<n<<" is not prime";
  cout<<endl;
  return 0;
}
