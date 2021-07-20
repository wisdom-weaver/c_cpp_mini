#include <iostream>
using namespace std;

int main()
{
  int a = 10; // stored in stack

  int *p = new int();
  *p = 10; // stored in memory heap
  delete p;

  p = new int[4];
  delete[] p; // releases memory 
  // but pointer is already dangling to that location in vain
  p = NULL; // we make it null so that no pointer reference exists

  return 0;
}