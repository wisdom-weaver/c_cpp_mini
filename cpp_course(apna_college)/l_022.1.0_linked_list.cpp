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

void insert_at_head(node *&head, int n)
{
  node *new_node = new node(n);
  new_node->next = head;
  head = new_node;
}

void insert_at_tail(node *&head, int n)
{
  if (head == NULL)
    return insert_at_head(head, n);

  node *new_node = new node(n);
  node *temp = head;
  while (temp->next != NULL)
    temp = temp->next;
  temp->next = new_node;
}

void insert_at_pos(node *&head, int n, int pos)
{
  if (pos == 0)
    return insert_at_head(head, n);
  node *new_node = new node(n);
  node *temp = head;
  int i = 0;
  for (; temp->next != NULL && i < pos; temp = temp->next, i++)
    if (i == pos - 1)
    {
      new_node->next = temp->next;
      temp->next = new_node;
      return;
    }
}

void deletion_at_head(node *&head)
{
  if (head == NULL)
    return;
  node *to_del = head;
  head = head->next;
  delete to_del;
}

void deletion_at_key(node *&head, int key)
{
  node *temp = head;
  if (temp == NULL)
    return;
  if (temp->data == key)
    return deletion_at_head(head);
  while (temp->next->data != key)
    temp = temp->next;
  if (temp == NULL)
    return;
  node *to_del = temp->next;
  temp->next = temp->next->next;
  delete to_del;
}

void deletion_at_tail(node *&head)
{
  node *temp = head;

  if (temp == NULL)
    return;
  if (temp->next == NULL)
    return deletion_at_head(head);

  node *last = NULL;
  node *sec_last = last;
  for (; temp != NULL; temp = temp->next)
  {
    sec_last = last;
    last = temp;
  }
  node *to_del = last;
  sec_last->next = NULL;
  delete last;
}

void deletion_at_pos(node *&head, int pos)
{
  node *temp = head;
  if (temp == NULL)
    return;
  if (pos == 0)
    return deletion_at_head(head);

  node *at_pos;
  node *at_pos_prev = at_pos;
  int i = 0;
  bool found = false;
  for (; i <= pos && temp != NULL; i++, temp = temp->next)
  {
    at_pos_prev = at_pos;
    at_pos = temp;
    if (i == pos)
      found = true;
  }
  if (found == true)
  {
    at_pos_prev->next = at_pos->next;
    delete at_pos;
  }
}

int search(node *&head, int key)
{
  int i = 0;
  for (node *temp = head; temp != NULL; temp = temp->next, i++)
    if (temp->data == key)
      return i;
  return -1;
}

void display(node *&head)
{
  cout << "HEAD-> ";
  for (node *temp = head; temp != NULL; temp = temp->next)
  {
    cout << temp->data << "-> ";
  }
  cout << "NULL\n";
}

node *reverse(node *&head)
{
  node *prev_ptr = NULL;
  node *curr_ptr = head;
  node *next_ptr;
  while (curr_ptr != NULL)
  {
    next_ptr = curr_ptr->next;
    curr_ptr->next = prev_ptr;

    prev_ptr = curr_ptr;
    curr_ptr = next_ptr;
  }
  return prev_ptr;
}

node *reverse_rec(node *&head)
{
  if (head == NULL || head->next == NULL)
    return head;
  node *new_head = reverse_rec(head->next);
  head->next->next = head;
  head->next = NULL;
  return new_head;
}

node *reverse_k(node *&head, int k)
{
  node *prev_ptr = NULL;
  node *curr_ptr = head;
  node *next_ptr;
  int i = 0;
  while (curr_ptr != NULL && i < k)
  {
    next_ptr = curr_ptr->next;
    curr_ptr->next = prev_ptr;

    prev_ptr = curr_ptr;
    curr_ptr = next_ptr;
    i++;
  }
  if (next_ptr != NULL)
  {

    head->next = reverse_k(next_ptr, k);
  }
  return prev_ptr;
}

int main()
{
  node *head = NULL;
  // insert_at_head(head, 1);
  // insert_at_tail(head, 2);
  // insert_at_tail(head, 3);
  // insert_at_head(head, 4);
  // insert_at_pos(head, 5, 2);
  // display(head);
  // cout << search(head, 2) << endl;
  // deletion_at_key(head, 3);
  // display(head);
  // deletion_at_pos(head, 1);
  // display(head);
  // deletion_at_head(head);
  // display(head);
  // deletion_at_tail(head);
  // display(head);

  // reverse all nodes
  // insert_at_tail(head, 1);
  // insert_at_tail(head, 2);
  // insert_at_tail(head, 3);
  // insert_at_tail(head, 4);
  // display(head);

  // iterative
  //  head = reverse(head);
  // display(head);

  // recursive
  // head = reverse_rec(head);
  // display(head);

  // reverse k nodes
  insert_at_tail(head, 1);
  insert_at_tail(head, 2);
  insert_at_tail(head, 3);
  insert_at_tail(head, 4);
  insert_at_tail(head, 5);
  insert_at_tail(head, 6);
  display(head);
  head = reverse_k(head, 2);
  display(head);

  return 0;
}
