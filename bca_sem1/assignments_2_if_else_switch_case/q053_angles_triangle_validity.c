#include <stdio.h>
// #include <conio.h>

int main(){
  int a, b, c;
  printf("Enter angles of triangle: ");
  scanf("%d %d %d", &a, &b, &c);
  
  if(a+b+c == 180)
    printf("Triangle is valid\n");
  else 
    printf("Triangle is not valid\n");

  // getch();
  // clrscr();
  return 0;
}
/* Console

Enter angles of triangle: 60 40 50
Triangle is not valid

Enter angles of triangle: 60 50 70
Triangle is valid

*/