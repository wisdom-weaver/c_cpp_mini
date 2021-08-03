#include <iostream>
using namespace std;

class base
{
public:
  void print() { cout << "base class - print\n"; }
  virtual void display() { cout << "base class - display\n"; }
};

class derived : public base
{
public:
  void print() { cout << "derived class - print\n"; }
  void display() { cout << "derived class - display\n"; }
};

int main()
{
  base *base_ptr;
  derived d;
  base_ptr = &d;

  base_ptr->print(); // staic binding - at decides which fucntion to call at compile time
  base_ptr->display(); // dynamic binding - at runtime changes which function to call

  return 0;
}

// compexity O(n)