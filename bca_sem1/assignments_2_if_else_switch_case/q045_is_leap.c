#include <stdio.h>
// #include <conio.h>

int main(){
  int n;
  printf("Enter n:");
  scanf("%d", &n);

  if( n%400==0 || (n%4==0 && n%100!=0) )
    printf("%d is a leap year\n", n);
  else 
    printf("%d is not a leap year\n", n);

  // getch();
  // clrscr();
  return 0;
}
/* Console

Enter n:2004
2004 is a leap year

Enter n:1900
1900 is not a leap year

Enter n:2400
2400 is a leap year

*/