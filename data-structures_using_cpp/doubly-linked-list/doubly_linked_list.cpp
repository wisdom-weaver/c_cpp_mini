#include <iostream>
using namespace std; 

class node{
  public: 
    int data;
    node* prev;
    node* next;
  
    node(int val){
      data = val;
      prev = NULL;
      next = NULL;
    }
};

int get_size(node* &head){
  node* temp = head;
  int size = 0;
  while(temp!=NULL){
    temp = temp->next;
    size++;
  }
  return size;
}

void insert_at_head(node* &head, int val){
  node* new_node = new node(val);
  new_node->next = head;
  if(head!=NULL) // to eleminate error at empty list
  head->prev = new_node;
  head = new_node;
}

void insert_at_tail(node *&head, int val){
  if(head==NULL) return insert_at_head(head, val);
  node* new_node = new node(val);
  node* temp = head;
  while(temp->next != NULL)
    temp = temp->next;
  temp->next = new_node;
  new_node->prev = temp;
}

void deletion_at_head(node* &head){
  node *temp = head;
  node* to_delete = head;

  head = head->next;
  head->prev=NULL; // the prev of head node must point to nothing 

  delete to_delete;
}

void deletion_at_pos(node* &head, int pos){
  // if we need to delete the 1st node
  if(pos==0) deletion_at_head(head);

  node* temp = head; 
  int counter=0;
  while( temp!=NULL && counter!=pos ){
    temp = temp->next; counter++;
  }
  temp->prev->next = temp->next;
  if(temp->next!=NULL) // to eliminate error at last node
  temp->next->prev = temp->prev;
  delete temp;
}

void deletion_at_tail(node* head){
  int size = get_size(head);
  return deletion_at_pos(head, size-1);
}

void display(node* &head){
  if(head==NULL){ cout<<"NULL"<<endl; return; }
  node* temp = head;
  cout<<"NULL <-> ";
  while(temp!=NULL){
    cout<<temp->data<<" <-> ";
    temp = temp->next;
  }
  cout<<"NULL"<<endl;
}

void silent_add_nodes_asc(node* &head, int n){
  int i=0;
  while(i<n) insert_at_tail(head, ++i);
}
void test_insert_at_head(){
  node* head = NULL;
  int n=5, i=0;
  while(display(head), i<n) insert_at_head(head, ++i);
}
void test_insert_at_tail(){
  node* head = NULL;
  int n=5, i=0;
  while(display(head), i<n) insert_at_tail(head, ++i);
}
void test_deletion_at_pos(){
  node* head = NULL;
  silent_add_nodes_asc(head, 5);
  cout<<"Before: "; display(head);
  int pos = 3;
  cout<<"Deleting(0-indexing) pos= "<<pos<<endl;
  deletion_at_pos(head, pos);
  cout<<"After : "; display(head);
}
void test_deletion_at_head(){
  node* head = NULL; silent_add_nodes_asc(head, 5);
  cout<<"Before: "; display(head);
  deletion_at_head(head);
  cout<<"After : "; display(head);
}
void test_deletion_at_tail(){
  node* head = NULL; silent_add_nodes_asc(head, 5);
  cout<<"Before: "; display(head);
  deletion_at_tail(head);
  cout<<"After : "; display(head);
}


int main(){
  // node* head = NULL;
  // display(head);

  // test_insert_at_head();
  // test_insert_at_tail();
  // test_deletion_at_pos();
  // test_deletion_at_head();
  // test_deletion_at_tail();
  return 0;
}