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

void make_cycle(node *head, int pos)
{
  node *temp = head;
  node *startNode;
  int count = 1;
  while (temp->next != NULL)
  {
    if (count == pos)
      startNode = temp;
    temp = temp->next;
    count++;
  }
  temp->next = startNode;
}

bool detect_cycle(node *&head)
{
  node *slow = head;
  node *fast = head;
  while (fast != NULL && fast->next != NULL)
  {
    slow = slow->next;
    fast = fast->next->next;
    if (fast == slow)
      return true;
  }
  return false;
}

void remove_cycle(node *head)
{
  node *slow = head;
  node *fast = head;
  do
  {
    slow = slow->next;
    fast = fast->next->next;
  } while (fast != slow);

  fast = head;
  while (slow->next != fast->next)
  {
    slow = slow->next;
    fast = fast->next;
  }
  slow->next = NULL;
}

int length(node *head)
{
  int l = 0;
  node *temp = head;
  while (temp != NULL)
  {
    l++;
    temp = temp->next;
  }
  return l;
}

node *k_append(node *&head, int k)
{
  node *new_head;
  node *new_tail;
  node *tail = head;

  int l = length(head);
  int c = 1;
  k = k % l;
  while (tail->next != NULL)
  {
    if (c == l - k)
      new_tail = tail;
    if (c == l - k + 1)
      new_head = tail;
    tail = tail->next;
    c++;
  }
  new_tail->next = NULL;
  tail->next = head;
  return new_head;
}

node *from_ar(int *ar, int n)
{
  node *head = NULL;
  for (int i = 0; i < n; i++)
    insert_at_tail(head, ar[i]);
  return head;
}

void intersect(node *&ll1, node *&ll2, int n)
{
  node *temp1 = ll1;
  node *temp2 = ll2;
  while (n--)
    temp1 = temp1->next;
  while (temp2->next != NULL)
    temp2 = temp2->next;
  temp2->next = temp1;
}

int intersection(node *&ll1, node *&ll2)
{
  int l1 = length(ll1);
  int l2 = length(ll2);
  int d = 0;
  node *p1;
  node *p2;
  if (l1 > l2)
  {
    d = l1 - l2;
    p1 = ll1;
    p2 = ll2;
  }
  else
  {
    d = l2 - l1;
    p1 = ll2;
    p2 = ll1;
  }
  while (d--)
  {
    p1 = p1->next;
    if (p1 == NULL)
      return -999;
  }

  while (p1 != NULL && p2 != NULL)
  {
    if (p1 == p2)
      return p1->data;
    p1 = p1->next;
    p2 = p2->next;
  }
  return -999;
}

node *merge_sorted(node *&ll1, node *&ll2)
{
  node *p1 = ll1;
  node *p2 = ll2;
  node *dummy_node = new node(-1);
  node *p3 = dummy_node;
  while (p1 != NULL && p2 != NULL)
  {
    if (p1->data < p2->data)
    {
      p3->next = p1;
      p1 = p1->next;
    }
    else
    {
      p3->next = p2;
      p2 = p2->next;
    }
    p3 = p3->next;
  }
  while (p1 != NULL)
  {
    p3->next = p1;
    p1 = p1->next;
    p3 = p3->next;
  }
  while (p2 != NULL)
  {
    p3->next = p2;
    p2 = p2->next;
    p3 = p3->next;
  }
  return dummy_node->next;
}

node *merge_sorted_rec(node *&ll1, node *&ll2)
{
  node *result;
  if (ll1 == NULL)
    return ll2;
  if (ll2 == NULL)
    return ll1;
  if (ll1->data < ll2->data)
  {
    result = ll1;
    result->next = merge_sorted_rec(ll1->next, ll2);
  }
  else
  {
    result = ll2;
    result->next = merge_sorted_rec(ll1, ll2->next);
  }
  return result;
}

void even_after_odd(node *&head)
{
  node *odd = head;
  node *even = head->next;
  node *even_start = even;
  while (odd->next != NULL && even->next != NULL)
  {
    odd->next = even->next;
    odd = odd->next;
    even->next = odd->next;
    even = even->next;
  }
  odd->next = even_start;
  if (odd->next != NULL)
    even->next = NULL;
}

int main()
{
  // node *head = NULL;
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
  // insert_at_tail(head, 1);
  // insert_at_tail(head, 2);
  // insert_at_tail(head, 3);
  // insert_at_tail(head, 4);
  // insert_at_tail(head, 5);
  // insert_at_tail(head, 6);
  // display(head);
  // head = reverse_k(head, 2);
  // display(head);

  // detection and removal of cycle
  // make_cycle(head, 3);
  // // display(head); // infinite printing
  // cout << "detect cycle: " << detect_cycle(head) << endl;
  // remove_cycle(head);
  // display(head);

  // head = k_append(head, 2);
  // display(head);

  // intersection
  // int ar1[] = {1, 2, 3, 4, 5};
  // int ar2[] = {11, 12};
  // node *ll1 = from_ar(ar1, 5);
  // node *ll2 = from_ar(ar2, 2);
  // intersect(ll1, ll2, 3);
  // display(ll1);
  // display(ll2);
  // cout << "intersection point: " << intersection(ll1, ll2);

  // merge sort
  // int ar1[] = {1, 4, 7, 8, 10};
  // int ar2[] = {2, 3, 9, 16};
  // node *ll1 = from_ar(ar1, 5);
  // node *ll2 = from_ar(ar2, 4);
  // display(ll1);
  // display(ll2);
  // node *mer = merge_sorted_rec(ll1, ll2);
  // // node *mer = merge_sorted(ll1, ll2);
  // display(mer);

  //even pos nodes after odd pos nodes
  // int ar[] = {1, 2, 3, 4, 5, 6};
  // node *head = from_ar(ar, 6);
  // display(head);
  // even_after_odd(head);
  // display(head);

  return 0;
}
