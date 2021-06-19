#include <stdio.h>
// #include <conio.h>

int main(){
  float bs, gs;
  printf("Enter basic salary: Rs"); scanf("%f", &bs);

  if(bs<=10000) gs = bs*(1+0.20+0.80);
  else if(bs<=20000) gs = bs*(1+0.25+0.90);
  else gs = bs*(1+0.30+0.95);

  printf("Gross Salary: Rs%-.2f", gs);

  // getch();
  // clrscr();
  return 0;
}
/* Console

Enter basic salary: Rs3000.00
Gross Salary: Rs6000.00

*/