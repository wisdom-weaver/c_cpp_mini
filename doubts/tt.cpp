#include <iostream>
#include <typeinfo>
using namespace std;

template <typename T>
void test_fn(T a) {
  string s = typeid(a).name();
  string out = (s == "i") ? "true" : "false";
  cout << out << endl;
}

int main() {
  test_fn(5);
  test_fn("A");
  test_fn('D');
  test_fn(3.44);
  int ar[] = {1, 2, 3};
  test_fn(ar);
  return 0;
}