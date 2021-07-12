#include <iostream>
#include <fstream>
using namespace std;

int main()
{
  ofstream fo("./text.txt");
  cout << "Enter name:";
  string name;
  getline(cin, name);
  fo << name << endl;
  fo.close();

  ifstream fi("./text.txt");
  cout<<"\nreading from file:\n ";
  string name2;
  getline(fi, name2);
  cout<<name2;
  fi.close();


  return 0;
}