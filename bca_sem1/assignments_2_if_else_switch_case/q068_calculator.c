#include <stdio.h>
#include <math.h>
// #include <conio.h>

int main()
{
  int a, b;  char op;
  printf("Enter expression ( operand [operator] operand ): ");
  printf(": ");
  scanf("%d %c %d", &a, &op, &b);

  switch(op){
    case '+': printf("=> %d", a+b); break;
    case '-': printf("=> %d", a-b); break;
    case '*': printf("=> %d", a*b); break;
    case '%': printf("=> %d", a%b); break;
    case '/': printf("=> %0.2f", (float)a/b); break;
    default: printf("Expression couldn't be evaluated");
  }

  // getch();
  // clrscr();
  return 0;
}
/* Console


Enter expression ( operand [operator] operand ): : 1 + 2
=> 3

Enter expression ( operand [operator] operand ): : 6 / 3
=> 2.00

Enter expression ( operand [operator] operand ): : 5 % 2
=> 1

*/