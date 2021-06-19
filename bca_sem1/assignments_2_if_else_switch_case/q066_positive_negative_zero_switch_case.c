#include <stdio.h>
// #include <conio.h>

int main(){
  int n;
  printf("Enter n: "); scanf("%d", &n);
  
  switch(n){
    case 0: printf("%d is zero\n", n); break;
    default: {
      switch(n>0){
        case 1:  printf("%d is positive\n", n); break;
        default: printf("%d is negative\n", n); break;
      }
    }
  }

  // getch();
  // clrscr();
  return 0;
}
/* Console

Enter n: 0
0 is zero

Enter n: 32
32 is positive

Enter n: -98
-98 is negative

*/