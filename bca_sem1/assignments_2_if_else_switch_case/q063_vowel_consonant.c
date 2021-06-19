#include <stdio.h>
// #include <conio.h>

int main(){
  char ch; int check;
  printf("Enter ch: "); 
  ch = getchar();
  check = (ch=='A' || ch=='E' || ch=='I' || ch=='O' || ch=='U' || ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u' );
  switch(check){
    case  1: printf("%c is a vowel", ch); break;
    default: printf("%c is a consonant", ch); break;
  }

  // getch();
  // clrscr();
  return 0;
}
/* Console

Enter ch: a
a is a vowel

Enter ch: y
y is a consonant

*/