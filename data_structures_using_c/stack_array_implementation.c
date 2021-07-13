#include <stdio.h>
#define MAX 20
int stack[MAX];
int top = -1;

void push(int n)
{
  if (top == MAX - 1)
  {
    printf("Overflow Exception: stack full\n");
    return;
  }
  stack[++top] = n;
}
int pop()
{
  if (top == -1)
  {
    printf("Undeflow Exception: stack empty\n");
    return -999;
  }
  int el = stack[top];
  top--;
  return el;
}
void display()
{
  printf("=> Stack: ");
  if (top == -1)
  {
    printf("EMPTY\n");
    return;
  }
  for (int i = 0; i <= top; i++)
    printf("%d -> ", stack[i]);
  printf("TOP\n");
}

int main()
{
  // for (int i = 1; i < 5; i++)
  //   push(i);
  // display();

  // printf("pop elem: %d\n", pop());
  // printf("pop elem: %d\n", pop());
  // printf("pop elem: %d\n", pop());
  // display();
  // printf("pop elem: %d\n", pop());
  // printf("pop elem: %d\n", pop());

  // for (int i = 1; i < 22; i++)
  //   push(i);

  int choice;
help:
  printf("\n# 1: push");
  printf("\n# 2: pop");
  printf("\n# 3: display");
  printf("\n# 4: help");
  printf("\n# 0: exit");
  do
  {

    printf("\nEnter chioce: ");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
    {
      int n;
      printf("Enter n: ");
      scanf("%d", &n);
      push(n);
      break;
    }
    case 2:
    {
      printf("pop elem: %d\n", pop());
      break;
    }
    case 3:
      display();
      break;
    case 4:
      goto help;
    default:
      goto help;
    }
    printf("-----\n");
  } while (choice);

  return 0;
}