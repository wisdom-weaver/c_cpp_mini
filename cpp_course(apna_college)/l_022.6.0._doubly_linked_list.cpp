#include <iostream>
using namespace std;

class node
{
public:
  int data;
  node *next;
  node *prev;
  node(int val)
  {
    data = val;
    next = NULL;
    prev = NULL;
  }
};

void insert_at_head(node *&head, int val)
{
  node *new_node = new node(val);
  new_node->next = head;
  if (head != NULL)
    head->prev = new_node;
  head = new_node;
}

void insert_at_tail(node *&head, int val)
{
  if (head == NULL)
    return insert_at_head(head, val);
  node *
      new_node = new node(val);
  node *temp = head;
  while (temp->next != NULL)
    temp = temp->next;
  temp->next = new_node;
  new_node->prev = temp;
}

void delete_at_head(node *&head)
{
  node *to_del = head;
  head = head->next;
  head->prev = NULL;
  delete to_del;
}

void delete_at_pos(node *head, int pos)
{
  if (pos == 0)
    return delete_at_head(head);

  node *temp = head;
  int i = 0;
  while (i != pos && temp != NULL)
  {
    i++;
    temp = temp->next;
  }
  temp->prev->next = temp->next;
  if (temp->next != NULL)
    temp->next->prev = temp->prev;
  delete temp;
}

void display(node *&head)
{
  node *temp = head;
  cout << "HEAD-> ";
  while (temp != NULL)
  {
    cout << temp->data << "<-> ";
    temp = temp->next;
  }
  cout << "NULL\n";
}

int main()
{
  node *head = NULL;
  // insert_at_head(head, 1);
  insert_at_head(head, 1);
  insert_at_head(head, 2);
  insert_at_tail(head, 3);
  insert_at_tail(head, 4);
  insert_at_tail(head, 5);
  insert_at_tail(head, 6);
  display(head);
  delete_at_pos(head, 2);
  display(head);
  delete_at_head(head);
  display(head);

  return 0;
}
