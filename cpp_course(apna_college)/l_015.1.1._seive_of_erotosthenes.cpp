#include <iostream>
#include <string>
using namespace std;

int c=0;

// sieve of erotosthenes
void primeSieve(int n)
{
  int prime[1001] = {0};

  for (int i = 2; i <= n; i++)
    if (prime[i] == 0)
      for (int j = i * i; j <= n; j += i){
        c++;
        prime[j] = 1;
        }
  
  cout << "prime: ";
  for (int i = 2; i <= n; i++)
    if (prime[i] == 0)
      cout << i << ", ";
  cout << endl;
  cout<<"runner:"<<c;
}

int main()
{
  primeSieve(1000);
  return 0;
}

// https://www.youtube.com/watch?v=nDPo9hsDNvU&list=PLfqMhTWNBTe0b2nM6JHVCnAkhQRGiZMSJ&index=36