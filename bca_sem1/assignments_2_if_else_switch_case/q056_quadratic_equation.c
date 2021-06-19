#include <stdio.h>
#include <math.h>
// #include <conio.h>

int main(){
  int a, b, c;
  float D, r1, r2;
  printf("Enter a b c in equaiton ax^2 + bx + c ==0 : ");
  scanf("%d %d %d", &a, &b, &c);
  
  D = b*b - 4*a*c;

  if(D==0){
    r1 = -b/(2.0*a);
    printf("Single real root: %0.3f \n", r1);
  }else if(D>0){
    r1 = (-b + sqrt(D))/(2.0*a);
    r2 = (-b - sqrt(D))/(2.0*a);
    printf("real & distinct roots: %0.3f\t %0.3f\n", r1, r2);
  }else{
    r1 = -b / (2.0*a);
    r2 =  sqrt(-D) / (2.0*a);
    printf("conplex roots: => \n");
    printf("%0.3f + %0.3f i \n", r1, r2);
    printf("%0.3f - %0.3f i \n", r1, r2);
  }

  // getch();
  // clrscr();
  return 0;
}
/* Console

Enter a b c in equaiton ax^2 + bx + c ==0 : 1 0 -16       
real & distinct roots: 4.000     -4.000

Enter a b c in equaiton ax^2 + bx + c ==0 : 1 2 1
Single real root: -1.000 

Enter a b c in equaiton ax^2 + bx + c ==0 : 1 1 1
conplex roots: => 
-0.500 + 0.866 i
-0.500 - 0.866 i

*/