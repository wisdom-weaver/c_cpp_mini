#include <stdio.h>
// #include <conio.h>

int main(){
  int day;
  printf("Enter day: "); scanf("%d", &day);
  switch(day){
    case 1: printf("Sunday\n"); break;
    case 2: printf("Monday\n"); break;
    case 3: printf("Tuesday\n"); break;
    case 4: printf("Wednesday\n"); break;
    case 5: printf("Thursday\n"); break;
    case 6: printf("Friday\n"); break;
    case 7: printf("Satday\n"); break;
    default: printf("Invalid day no\n");
  }

  // getch();
  // clrscr();
  return 0;
}
/* Console

Enter day: 2
Monday

Enter day: 7
Satday

Enter day: 12
Invalid day no

*/