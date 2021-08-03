#include <iostream>
using namespace std;

class A
{
public:
  int a;
  void funcA()
  {
    cout << "funcA\n";
  }

private:
  int b;
  void funcB()
  {
    cout << "funcB\n";
  }

protected:
  int c;
  void funcC()
  {
    cout << "funcC\n";
  }
};

int main()
{
  A obj;
  obj.funcA();
  // obj.funcB();
  // obj.funcC();
  return 0;
}

// compexity O(n)