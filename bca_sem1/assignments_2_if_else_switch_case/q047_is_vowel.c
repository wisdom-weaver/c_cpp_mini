#include <stdio.h>
#include <ctype.h>
// #include <conio.h>

int main(){
  char ch;
  printf("Enter ch: ");
  ch = getchar();
  
  if(!isalpha(ch))
    printf("%c is not an alphabet\n", ch);
  else if(
    ch=='A' || ch=='E' || ch =='I' || ch =='O' || ch=='U' || 
    ch=='a' || ch=='e' || ch =='i' || ch =='o' || ch=='u' 
  )
    printf("%c is a vowel\n", ch);
  else 
    printf("%c is a consonant\n", ch);

  // getch();
  // clrscr();
  return 0;
}
/* Console

Enter ch: a
a is a vowel

Enter ch: O
O is a vowel

Enter ch: f
f is a consonant

*/