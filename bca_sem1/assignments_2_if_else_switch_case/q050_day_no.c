#include <stdio.h>
#include <ctype.h>
// #include <conio.h>

int main(){
  int n;
  printf("Enter n: ");
  scanf("%d", &n);
  
  if(n==1) printf("Sunday\n");
  else if(n==2) printf("Monday\n");
  else if(n==3) printf("Tuesday\n");
  else if(n==4) printf("Wednesday\n");
  else if(n==5) printf("Thrusday\n");
  else if(n==6) printf("Friday\n");
  else if(n==7) printf("Saturday\n");
  else  printf("invalid day no. \n");

  // getch();
  // clrscr();
  return 0;
}
/* Console

Enter n: 1
Sunday

Enter n: 7
Saturday

Enter n: 34
invalid day no. 

*/