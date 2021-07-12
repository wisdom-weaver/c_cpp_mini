#include <stdio.h>
#include <stdlib.h>

struct node_stru
{
  int data;
  struct node *next;
};
typedef struct node_stru node;

node *head = NULL;
int len = 0;

node *new_node(int n)
{
  node *temp = (node *)malloc(sizeof(node));
  temp->data = n;
  temp->next = NULL;
  return temp;
}

void insert_at_beg(int n)
{
  node *temp = new_node(n);
  if (head == NULL)
  {
    head = temp;
    return;
  }
  temp->next = head;
  head = temp;
}

void insert_at_end(int n)
{
  node *temp = head;
  node *nnode = new_node(n);
  while (temp->next != NULL)
    temp = temp->next;
  temp->next = nnode;
}

void insert_at_pos(int n, int pos)
{
  if (pos == 0)
    return insert_at_beg(n);

  node *temp = head;
  node *nnode = new_node(n);
  int i = 0;
  while (temp->next != NULL && i < pos - 1)
  {
    temp = temp->next;
    i++;
  }
  nnode->next = temp->next;
  temp->next = nnode;
}

void print_list()
{
  node *temp = head;
  printf("List: ");
  while (temp != NULL)
  {
    printf("%d->", temp->data);
    temp = temp->next;
  }
  printf("END\n");
}

void delete_from_beg()
{
  node *del = head;
  if (head->next == NULL || head == NULL)
  {
    head = NULL;
  }
  else
  {
    head = head->next;
  }
  // free(del);
}

void delete_from_end()
{
  if (head->next == NULL || head == NULL)
  {
    node *del = head;
    head = NULL;
    free(del);
    return;
  }
  node *sec_last, *last = head;
  while (last->next != NULL)
  {
    sec_last = last;
    last = last->next;
  }
  sec_last->next = NULL;
  free(last);
}

void delete_from_pos(int pos)
{
  if (head->next == NULL || head == NULL)
  {
    node *del = head;
    head = NULL;
    free(del);
    return;
  }
  if (pos == 0)
    return delete_from_beg();
  int i = 0;
  node *del_prev, *del = head;
  while (del->next != NULL && i < pos)
  {
    del_prev = del;
    del = del->next;
    i++;
  }
  del_prev->next = del->next;
  free(del);
}

int main()
{
  insert_at_beg(1);
  insert_at_beg(2);
  insert_at_end(4);
  insert_at_end(5);
  insert_at_end(6);
  insert_at_end(7);
  insert_at_pos(3, 2);
  print_list(head);

  delete_from_pos(2);
  delete_from_beg();
  delete_from_end();
  print_list(head);

  return 0;
}