#include <stdio.h>

const int N = 20;
int q[20];
int front = -1;
int rear = -1;

void enqueue(int n)
{
  if (rear == N - 1)
  {
    printf("Overflow\n");
    return;
  }
  if (front == -1)
    front = 0;
  q[++rear] = n;
}

int dequeue()
{
  if (front == -1 || front > rear)
  {
    printf("Underflow\n");
    return -999;
  }
  int el = q[front++];
  return el;
}

void display()
{
  printf("=> Queue: ");
  if (front == -1 || front > rear)
  {
    printf("EMPTY\n");
    return;
  }
  // printf("%d, %d", front, rear);
  printf("Front-> ");
  for (int i = front; i <= rear; i++)
    printf("%d-> ", q[i]);
  printf("Rear\n");
}

int main()
{
  enqueue(1);
  enqueue(2);
  enqueue(3);
  display();
  printf("Dequeue elem: %d\n", dequeue());
  printf("Dequeue elem: %d\n", dequeue());
  printf("Dequeue elem: %d\n", dequeue());
  printf("Dequeue elem: %d\n", dequeue());
  display();
  enqueue(4);
  enqueue(5);
  display();


  return 0;
}