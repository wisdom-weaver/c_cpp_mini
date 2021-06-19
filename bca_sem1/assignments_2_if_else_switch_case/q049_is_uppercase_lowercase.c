#include <stdio.h>
#include <ctype.h>
// #include <conio.h>

int main(){
  char ch;
  printf("Enter ch: ");
  ch = getchar();
  
  if( ch>='A' && ch<='Z' )
    printf("%c is uppercase\n", ch);
  else if( ch>='a' && ch<='z' )
    printf("%c is lowercase\n", ch);
  else 
    printf("%c is not an alphabet\n", ch);

  // getch();
  // clrscr();
  return 0;
}
/* Console

Enter ch: A
A is uppercase

Enter ch: c
c is lowercase

*/