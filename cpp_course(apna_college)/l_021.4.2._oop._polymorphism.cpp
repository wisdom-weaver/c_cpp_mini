#include <iostream>
using namespace std;

// operator overloading

class Complex
{
private:
  int real, img;

public:
  Complex() {}
  Complex(int r, int i)
  {
    real = r;
    img = i;
  }
  Complex operator+(Complex const &obj)
  {
    Complex res;
    res.img = img + obj.img;
    res.real = real + obj.real;
    return res;
  }
  void display()
  {
    cout << real << " + i" << img << endl;
  }
};

int main()
{
  Complex c1(12, 7), c2(6, 7);
  Complex c3 = c1 + c2;
  c3.display();

  return 0;
}

// compexity O(n)