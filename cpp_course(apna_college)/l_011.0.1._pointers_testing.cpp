#include <iostream>
using namespace std;

void pass1(int *p)
{
  *p = *p + 1;
}

void pass2(int &p)
{
  p = p + 1;
}

int main()
{
  int a = 10;
  cout << "a: " << a << endl;
  pass1(&a);
  cout << "a: " << a << endl;
  pass2(a);
  cout << "a: " << a << endl;
  return 0;
}

/*

 a    : 10
*a_ptr: 10
&a    : 0x7ffeb65eedfc
 a_ptr: 0x7ffeb65eedfc
&a_ptr: 0x7ffeb65eee00

*/