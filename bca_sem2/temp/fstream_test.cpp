#include <iostream>
#include <fstream>
using namespace std;

int main()
{
  fstream f;
  cout << "Enter name:";
  string name;
  getline(cin, name);
  f.open("./text.txt", ios::out);
  f << name;
  f.close();

  f.open("./text.txt");
  string name2;
  getline(f, name2);
  cout << name2;
  f.close();

  return 0;
}