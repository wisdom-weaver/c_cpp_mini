#include <iostream>
using namespace std;

class node
{
public:
  int data;
  node *next;
  node(int val)
  {
    data = val;
    next = NULL;
  }
};

void insert_at_head(node *&head, int val)
{
  node *new_node = new node(val);
  if (head == NULL)
  {
    new_node->next = new_node;
    head = new_node;
    return;
  }
  node *temp = head;
  while (temp->next != head)
    temp = temp->next;
  temp->next = new_node;
  new_node->next = head;
  head = new_node;
}

void insert_at_tail(node *&head, int val)
{
  if (head == NULL)
    return insert_at_head(head, val);
  node *new_node = new node(val);
  node *temp = head;
  while (temp->next != head)
    temp = temp->next;
  temp->next = new_node;
  new_node->next = head;
}

void delete_at_head(node *&head)
{
  node *temp = head;
  while (temp->next != head)
    temp = temp->next;
  node *to_del = head;
  temp->next = head->next;
  head = head->next;
  delete to_del;
}

void deletion(node *&head, int pos)
{
  if (pos == 0)
    return delete_at_head(head);
  node *temp = head;
  int c = 0;
  while (c != pos - 1)
  {
    temp = temp->next;
    c++;
  }
  node *to_del = temp->next;
  temp->next = temp->next->next;
  delete to_del;
}

void display(node *&head)
{
  node *temp = head;
  cout << "HEAD-> ";
  do
  {
    cout << temp->data << "-> ";
    temp = temp->next;
  } while (temp->next != head);
  cout << "HEAD\n";
}

int main()
{
  node *head = NULL;
  insert_at_head(head, 1);
  insert_at_head(head, 2);
  insert_at_tail(head, 3);
  insert_at_tail(head, 4);
  insert_at_tail(head, 5);
  insert_at_tail(head, 6);
  display(head);
  deletion(head, 2);
  display(head);
  delete_at_head(head);
  display(head);
  deletion(head, 0);
  display(head);

  return 0;
}
