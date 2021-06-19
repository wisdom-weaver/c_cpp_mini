#include <stdio.h>
// #include <conio.h>

int notes[] = {2000, 500, 200, 100, 50, 20, 10, 5, 2, 1};

int main(){
  int n, i=0;
  // n=1800;
  printf("Enter n: ");
  scanf("%d", &n);
  while(n){
    if(n/notes[i]>0) 
      printf("%d notes of %d\n", n/notes[i], notes[i]);
    n%=notes[i++];
  }

  // getch();
  // clrscr();
  return 0;
}
/* Console

Enter n: 5672
2 notes of 2000
3 notes of 500
1 notes of 100
1 notes of 50
1 notes of 20
1 notes of 2

*/