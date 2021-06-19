#include <stdio.h>
// #include <conio.h>

int main(){
  int units; float cost=0, add;
  printf("Enter units: "); scanf("%d", &units);

  if(units<=50)
    cost = units*0.50;
  else if(units<=150)
    cost = 50*0.50 + (units-50)*0.75;
  else if(units<=250)
    cost = 50*0.50 + 100*0.75 + (units-150)*1.20;
  else if(units>250)
    cost = 50*0.50 + 100*0.75 + 100*1.20  + (units-250)*1.50;

  cost += cost*0.20;
  printf("cost: Rs %0.2f \n", cost);  
  
  // getch();
  // clrscr();
  return 0;
}
/* Console

Enter units: 200
cost: Rs 160.00 
cost: Rs 192.00 

Enter units: 300
cost: Rs 295.00 
cost: Rs 354.00 

*/