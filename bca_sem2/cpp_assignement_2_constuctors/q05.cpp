#include <iostream>
using namespace std;

class TestClass{
  public:
    int a, b;

    TestClass(): a(10), b(20) {};
    TestClass(int x, int y): a(x), b(y) {};
    void display(){
      cout << "a: " <<a<< endl;
      cout << "b: " <<b<< endl;
    }
};

int main(){
  TestClass t1;
  TestClass t2(30, 40); 
  cout << "\nValue of t1: \n"; t1.display();
  cout << "\nValue of t2: \n"; t2.display();
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