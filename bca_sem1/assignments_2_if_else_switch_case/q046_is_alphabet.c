#include <stdio.h>
// #include <conio.h>

int main(){
  char ch;
  printf("Enter ch: ");
  ch = getchar();

  if( (ch>='A' && ch<='Z') || (ch>='a' && ch<='z') )
    printf("%c is an alphabet\n", ch);
  else 
    printf("%c is not an alphabet\n", ch);

  // getch();
  // clrscr();
  return 0;
}
/* Console

Enter ch: D
D is an alphabet

Enter ch: c
c is an alphabet

Enter ch: %
% is not an alphabet

Enter ch: 6
6 is not an alphabet

*/