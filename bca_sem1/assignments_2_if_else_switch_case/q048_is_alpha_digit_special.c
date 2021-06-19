#include <stdio.h>
// #include <ctype.h>
// #include <conio.h>

int main(){
  char ch;
  printf("Enter ch: ");
  ch = getchar();
  
  
  if( (ch>='A' && ch<='Z') || (ch>='a' && ch<='z') ) // if( isalpha(ch) )
    printf("%c is an alphabet\n", ch);
  else if( ch>='0' && ch<='9' ) // else if( isdigit(ch) )
    printf("%c is a digit\n", ch);
  else 
    printf("%c is a special character\n", ch);

  // getch();
  // clrscr();
  return 0;
}
/* Console

Enter ch: A
A is an alphabet

Enter ch: 9
9 is a digit

Enter ch: *
* is a special character

*/