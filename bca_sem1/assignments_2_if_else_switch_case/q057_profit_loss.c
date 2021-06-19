#include <stdio.h>
// #include <conio.h>

int main(){
  float cp, sp;
  printf("Enter Selling Price : Rs"); scanf("%f", &sp);
  printf("Enter Cost Price : Rs"); scanf("%f", &cp);

  if(sp==cp)
    printf("No Profit/Loss");
  else if(sp>cp)
    printf("Profit: Rs%0.2f \n", sp-cp );
  else
    printf("Loss: Rs%0.2f \n", cp-sp );

  
  // getch();
  // clrscr();
  return 0;
}
/* Console

Enter Selling Price : Rs4000.00
Enter Cost Price : Rs3500.00         
Profit: Rs500.00 

Enter Selling Price : Rs900.00
Enter Cost Price : Rs1000.00
Loss: Rs100.00 

*/