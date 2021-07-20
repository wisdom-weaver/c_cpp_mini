#include <iostream>
using namespace std;

class Base
{
private:
  int vari = 10;

public:
  friend class Derived;
};

class Derived : private Base
{
public:
  void show_vari()
  {
    cout << "vari:" << vari << endl;
  }
};

int main()
{
  Derived d;
  d.show_vari();
  return 0;
}
