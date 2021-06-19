#include <stdio.h>
// #include <conio.h>

int main(){
  int n;
  printf("Enter n:");
  scanf("%d", &n);

  if(n==0)
    printf("n: %d is zero\n", n);
  else if(n>0)
    printf("n: %d is positive\n", n);
  else 
    printf("n: %d is negative\n", n);

  // getch();
  // clrscr();
  return 0;
}
/* Console

Enter n:32
n: 32 is positive

Enter n:0
n: 0 is zero

Enter n:-97
n: -97 is negative

*/