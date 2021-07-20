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
  void check_if_friend()
  {
    try
    {
      if (vari == 10)
        cout << "is friend";
      else
        throw -1;
    }
    catch (int x)
    {
      cout << "is not friend";
    }
  }
};

class Derived2 : private Base
{
public:
  void check_if_friend()
  {
    try
    {
      if (vari == 10)
        cout << "is friend";
      else
        throw -1;
    }
    catch (int x)
    {
      cout << "is not friend";
    }
  }
};


int main()
{
  Derived d;
  d.check_if_friend();
  return 0;
}
