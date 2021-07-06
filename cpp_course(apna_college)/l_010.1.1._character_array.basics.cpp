#include <iostream>
using namespace std;

int main()
{
  char ar[100] = "Apple";
  int i = 0;
  while (ar[i] != '\0')
    cout << ar[i++] << endl;
  cout<<ar<<endl;
  cout<<"[2]=>"<<ar[2]<<endl;
  return 0;
}