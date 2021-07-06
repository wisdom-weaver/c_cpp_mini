#include <iostream>
using namespace std;

int largest_word_len(char ar[])
{
  int mx = 0;
  int wl = 0;
  int i = 0;
  while (1)
  {
    if (ar[i] == ' ' || ar[i] == '\0')
    {
      mx = max(mx, wl);
      wl = 0;
    }
    else wl++;
    if (ar[i] == '\0')
      break;
    i++;
  }
  return mx;
}

int main()
{
  int n = 10;
  cin >> n;
  char ar[n + 1];
  // char ar[] = "this isa baseball";
  cin.ignore();
  cin.getline(ar, n+1);
  // cin.ignore();
  cout << ar << endl;

  cout << largest_word_len(ar)<<endl;
  return 0;
}