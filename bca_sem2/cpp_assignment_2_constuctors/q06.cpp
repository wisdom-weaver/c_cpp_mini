#include <iostream>
using namespace std;

class TestClass{
  public:
    int a;
    TestClass(){
      cout << endl << "Constructor Called" << endl;
      a = 12;
    }  
    ~TestClass(){
      cout << endl << "Destructor Called" << endl;
    }
};

int main(){
  TestClass t1;
  cout<<"t1.a = "<<t1.a;
  return 0;
}

/*output:

Value of t1: 
a: 10
b: 20

Value of t2: 
a: 30
b: 40
*/