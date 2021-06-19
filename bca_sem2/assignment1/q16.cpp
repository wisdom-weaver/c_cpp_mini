#include <iostream>
#include <cmath>
using namespace std;

int main(){
  int a,b,c,d,e;
  cout<<"Enter marks in 5 subjects: ";
  cin>>a>>b>>c>>d>>e;
  int max;
  cout<<"Enter maximum marks: ";
  cin>>max;
  int tot = a+b+c+d+e;
  float avg = (a+b+c+d+e)/5.0;
  float pect = tot*100.0/max; 
  float area = 1.73*pow(a,2)/4;
  cout<<"total ="<< tot<<endl;
  cout<<"average ="<< avg<<endl;
  cout<<"pect ="<< pect<<endl;
  return 0;
}
