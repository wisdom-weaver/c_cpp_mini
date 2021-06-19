// is alphabet

#include <iostream>
#include <cmath>
using namespace std;

int main(){
  char ch;
  cout<<"Enter character: ";
  cin>>ch;
  cout<<ch<<(((ch>='a'&&ch<='z') || (ch>='A'&&ch<='Z'))?" is ":" is not ")<<"alphabet"<<endl;
  return 0;
}
