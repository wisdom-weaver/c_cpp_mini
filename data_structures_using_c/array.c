#include <stdio.h>
#define N 20

void insert_at_start(int *ar, int *size, int k)
{
  for (int i = *size; i >= 0; i--)
    ar[i] = ar[i - 1];
  ar[0] = k;
  *size = *size + 1;
}

void insert_at_pos(int *ar, int *size, int k, int pos)
{
  for (int i = *size; i > pos; i--)
    ar[i] = ar[i - 1];
  ar[pos] = k;
  *size = *size + 1;
}

void insert_at_end(int *ar, int *size, int k)
{
  ar[*size] = k;
  *size = *size + 1;
}

void delete_from_start(int *ar, int *size)
{
  for (int i = 0; i < *size; i++)
    ar[i] = ar[i + 1];
  *size = *size - 1;
}

void delete_from_pos(int *ar, int *size, int pos)
{
  for (int i = pos; i < *size; i++)
    ar[i] = ar[i + 1];
  *size = *size - 1;
}

void delete_from_end(int *ar, int *size)
{
  ar[*size] = 0;
  *size = *size - 1;
}

void print_ar(int *ar, int *size)
{
  printf("Array: ");
  for (int i = 0; i < *size; i++)
    printf("%d ", ar[i]);
  printf("\n");
}

void fill_ar(int *ar, int size, int k)
{
  for (int i = 0; i < size; i++)
    ar[i] = k;
}

void initialize_ar(int *ar, int *size)
{
  printf("Enter size: ");
  scanf("%d", size);
  printf("Enter %d elems: ");
  for (int i = 0; i < *size; i++)
    scanf("%d", &ar[i]);
}

int main()
{
  int ar[N];
  int size = 0;
  fill_ar(ar, N, 0);
  initialize_ar(ar, &size);
  print_ar(ar, &size);

  for (int i = 1; i < 4; i++)
    insert_at_start(ar, &size, i);
  print_ar(ar, &size);
  for (int i = 1; i < 4; i++)
    insert_at_end(ar, &size, i);
  print_ar(ar, &size);
  insert_at_pos(ar, &size, 10, 2);
  print_ar(ar, &size);

  printf("\n");

  delete_from_pos(ar, &size, 2);
  print_ar(ar, &size);
  delete_from_start(ar, &size);
  print_ar(ar, &size);
  delete_from_end(ar, &size);
  print_ar(ar, &size);

  return 0;
}