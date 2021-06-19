#include <stdio.h>
// #include <conio.h>

int main(){
  int a,b,c, maximum;
  printf("Enter a b and c: ");
  scanf("%d %d %d", &a, &b, &c);
  if(a>b && a>c)
    maximum = a;
  else if(b>c && b>a)
    maximum = b;
  else 
    maximum = c;

  printf("%d is maximum out of %d %d %d \n", maximum, a, b, c);
  // getch();
  // clrscr();
  return 0;
}
/* Console

Enter a b and c: 3 4 8
8 is maximum out of 3 4 8 

*/