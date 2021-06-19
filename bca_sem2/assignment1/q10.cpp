#include <iostream>
using namespace std;

int main(){
  int d;
  cout<<"Enter days: ";
  cin>>d;
  int y = d/365;
  d = d%365;
  int w = d/7;
  d = d%7;
  cout<<y<<" years "<<w<<" weeks "<<d<<" days "<<endl;
  return 0;
}