#include <stdio.h>
// #include <conio.h>

int main(){
  int n;
  printf("Enter n:");
  scanf("%d", &n);

  if( n%5==0 && n%11==0 )
    printf("n: %d is divisible by 5 and 11\n", n);
  else 
    printf("n: %d is not divisible by 5 and 11\n", n);

  // getch();
  // clrscr();
  return 0;
}
/* Console

Enter n:55
n: 55 is divisible by 5 and 11

Enter n:32
n: 32 is not divisible by 5 and 11

*/