#include <stdio.h>
// #include <conio.h>

int main(){
  int n;
  printf("Enter n: "); scanf("%d", &n);
  
  switch(n%2==0){
    case 1: printf("%d is even", n); break;
    default: printf("%d is odd", n);
  }

  // getch();
  // clrscr();
  return 0;
}
/* Console

Enter n: 20
20 is even

Enter n: 21
21 is odd

*/