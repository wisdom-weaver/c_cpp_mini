#include <iostream>
using namespace std;

// function overloading

class AC
{
public:
  void fun()
  {
    cout << "I am a function with no args\n";
  }
  void fun(int x)
  {
    cout << "I am a function with int args\n";
  }
  void fun(double x)
  {
    cout << "I am a function with double args\n";
  }
};

int main()
{
  AC o;
  o.fun();
  o.fun(1);
  o.fun(1.2);

  return 0;
}

// compexity O(n)