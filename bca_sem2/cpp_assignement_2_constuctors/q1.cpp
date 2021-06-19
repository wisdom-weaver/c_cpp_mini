#include <iostream>
using namespace std;

class TestClass{
  public: 
    int x,y;
  TestClass(){
    cout<<"Default constructor of TestClass\n";
    x = 10;
    y = 20;
  }
};

int main(){
  TestClass t1;
  cout<<"x= "<<t1.x<<endl;
  cout<<"y= "<<t1.y<<endl;
  return 0;
}

/*
Output:
Default constructor of TestClass
x= 10
y= 20

*/