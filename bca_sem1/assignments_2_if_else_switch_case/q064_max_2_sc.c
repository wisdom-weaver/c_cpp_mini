#include <stdio.h>
// #include <conio.h>

int main(){
  int a, b;
  printf("Enter a and b: "); scanf("%d%d", &a, &b);
  
  switch(a>b){
    case 1: printf("largest: %d", a); break;
    default: printf("largest: %d", b); break;
  }

  // getch();
  // clrscr();
  return 0;
}
/* Console

Enter a and b: 3 6
largest: 6

Enter a and b: 3 1
largest: 3

*/