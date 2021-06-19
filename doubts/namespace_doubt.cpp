#include <iostream>
using namespace std;

class TestClass{
  public: int i;
  TestClass(int a){
    i = a;
  }
  void show();
};

void TestClass::show(){
  cout<<"i: "<<i<<endl;
}

int main(){
  TestClass ob(10);
  ob.show();
  return 0;
}