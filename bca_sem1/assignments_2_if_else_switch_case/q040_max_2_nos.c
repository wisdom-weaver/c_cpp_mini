#include <stdio.h>
// #include <conio.h>

int main(){
  int a,b;
  printf("Enter a and b: ");
  scanf("%d %d", &a, &b);
  if(a>b)
    printf("%d is maximum out of %d and %d \n", a, a, b);
  else
    printf("%d is maximum out of %d and %d \n", b, a, b);

  // getch();
  // clrscr();
  return 0;
}
/* Console

Enter a and b: 43 23
43 is maximum out of 43 and 23 
*/