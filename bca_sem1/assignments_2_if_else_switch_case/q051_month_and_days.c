#include <stdio.h>
#include <ctype.h>
// #include <conio.h>

int main(){
  int n;
  printf("Enter n: ");
  scanf("%d", &n);
  
  if(n== 1) printf("January => 31\n");
  else if(n== 2) printf("February => 28/29\n");
  else if(n== 3) printf("March => 31\n");
  else if(n== 4) printf("April => 30\n");
  else if(n== 5) printf("May => 31\n");
  else if(n== 6) printf("June => 30\n");
  else if(n== 7) printf("July => 31\n");
  else if(n== 8) printf("August => 31\n");
  else if(n== 9) printf("September => 30\n");
  else if(n==10) printf("October => 31\n");
  else if(n==11) printf("November => 30\n");
  else if(n==12) printf("December => 31\n");
  else  printf("invalid day no. \n");

  // getch();
  // clrscr();
  return 0;
}
/* Console

Enter n: 1
January => 31

Enter n: 4 
April => 30

Enter n: 434
invalid day no. 

*/