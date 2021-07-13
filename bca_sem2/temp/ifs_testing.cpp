#include <iostream>
#include <fstream>
using namespace std;

int main()
{
  ofstream fout;
  fout.open("./a.txt");
  fout << "line1_A\n";
  fout << "line2_A\n";
  fout.close();
  fout.open("./b.txt");
  fout << "line1_B\n";
  fout << "line2_B\n";
  fout.close();

  ifstream fin;
  int N = 30;
  char line[N + 1];
  fin.open("./a.txt");
  while (fin)
  {
    fin.getline(line, N);
    cout << line << endl;
  }
  fin.close();
  fin.open("./b.txt");
  while (fin)
  {
    fin.getline(line, N);
    cout << line << endl;
  }
  fin.close();
  return 1;
}