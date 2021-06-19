#include <stdio.h>
// #include <conio.h>

#define swap(a,b) {int temp=a; a=b; b=temp;}

int main(){
  int a, b, c;
  printf("Enter sides of triangle: ");
  scanf("%d %d %d", &a, &b, &c);
  
  if(a>b) swap(a,b);
  if(b>c) swap(b,c);
  
  if(a+b > c)
    printf("Triangle is valid\n");
  else 
    printf("Triangle is not valid\n");

  // getch();
  // clrscr();
  return 0;
}
/* Console

Enter sides of triangle: 3 3 3
Triangle is valid

Enter sides of triangle: 3 4 5
Triangle is valid

Enter sides of triangle: 5 10 18
Triangle is not valid

*/