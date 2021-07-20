#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

// sieve of erotosthenes
void primeSieve(int n)
{
  int prime[100] = {0};

  for (int i = 2; i <= n; i++)
    if (prime[i] == 0)
      for (int j = i * i; j <= n; j += i)
        prime[j] = 1;
  
  cout << "prime: ";
  for (int i = 2; i <= n; i++)
    if (prime[i] == 0)
      cout << i << ", ";
  cout << endl;
}

int main()
{
  primeSieve(50);
  return 0;
}

// https://www.youtube.com/watch?v=nDPo9hsDNvU&list=PLfqMhTWNBTe0b2nM6JHVCnAkhQRGiZMSJ&index=36