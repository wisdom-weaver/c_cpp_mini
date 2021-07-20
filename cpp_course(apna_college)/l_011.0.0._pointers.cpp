#include <iostream>
using namespace std;

void increment(int *i)
{
  *i = *i + 1;
}

void swap(int *a, int *b)
{
  int *temp = a;
  a = b;
  b = temp;
}

int main()
{
  int a = 10;
  int *a_ptr;
  a_ptr = &a;

  cout << " a    : " << a << endl;
  cout << "*a_ptr: " << *a_ptr << endl;
  cout << "&a    : " << &a << endl;
  cout << " a_ptr: " << a_ptr << endl;
  cout << "&a_ptr: " << &a_ptr << endl;

  cout << "\n-----\n\n";
  cout << " a_ptr: " << a_ptr << endl;
  cout << " a_ptr++" << endl;
  a_ptr++;
  cout << " a_ptr: " << a_ptr << endl;

  cout << "\n-----\n\n";
  int ar[] = {10, 20, 30};
  cout << *ar << endl;
  for (auto i = ar; i < ar + 3; i++)
    cout << *i << ", ";
  cout << "\n------\n\n";

  int b = 10;
  cout << "b: " << b << endl;
  increment(&b);
  cout << "b: " << b << endl;

  cout << "\n------\n\n";
  int c = 5, d = 6;
  cout << "c: " << c << " | d: " << d << endl;
  swap(&c, &d);
  cout << "c: " << c << " | d: " << d << endl;

  return 0;
}

/*

 a    : 10
*a_ptr: 10
&a    : 0x7ffeb65eedfc
 a_ptr: 0x7ffeb65eedfc
&a_ptr: 0x7ffeb65eee00

*/