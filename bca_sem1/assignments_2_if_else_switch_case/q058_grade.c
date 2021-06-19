#include <stdio.h>
// #include <conio.h>

int main(){
  int a,b,c,d,e, g_tot, tot; float per;
  printf("Enter marks in 5 subjects: "); scanf("%d%d%d%d%d", &a, &b, &c, &d, &e);
  printf("Enter max total of all subjects: "); scanf("%d", &g_tot);
  tot = a+b+c+d+e;
  per = tot/(float)g_tot*100.0;
  printf("Total: %d / %d \n", tot, g_tot);
  printf("Percentage: %0.2f \n", per);

  if(per>=90) printf("Grade A");
  else if(per>=80) printf("Grade B");
  else if(per>=70) printf("Grade C");
  else if(per>=60) printf("Grade D");
  else if(per>=40) printf("Grade E");
  else printf("Grade F");
  // getch();
  // clrscr();
  return 0;
}
/* Console

Enter marks in 5 subjects: 90 99 95 76 80
Enter max total of all subjects: 500
Total: 440 / 500 
Percentage: 88.00 
Grade B

*/