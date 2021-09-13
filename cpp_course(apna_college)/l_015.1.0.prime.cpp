#include <iostream>
#include <string>
using namespace std;

int c=0;

bool is_prime(int n){
  for(int i=2; i<=n/2; i++){
    c++;
    if(n%i==0) return false;
  }return true;
}

int main()
{
  int n =1000;
  for(int num=2;num<=n;num++)
   if(is_prime(num)) cout<<num<<",";
  cout<<"\n runner:"<<c;;
  return 0;
}
