#include <stdio.h>
// #include <conio.h>

int main(){
  int a, b, c;
  printf("Enter sides of triangle: ");
  scanf("%d %d %d", &a, &b, &c);
  
  if(a==b && b==c)
    printf("Triangle is equilateral\n");
  else if(a==b || b==c || a==c)
    printf("Triangle is isoceles\n");
  else 
    printf("Triangle is scalar\n");

  // getch();
  // clrscr();
  return 0;
}
/* Console

Enter sides of triangle: 3 3 3
Triangle is equilateral

Enter sides of triangle: 3 4 5
Triangle is scalar

Enter sides of triangle: 4 4 3
Triangle is isoceles

*/