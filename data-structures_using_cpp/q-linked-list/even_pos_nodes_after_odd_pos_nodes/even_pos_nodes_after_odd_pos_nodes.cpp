#include <iostream>
using namespace std;

class node{
  public:
    int data;
    node* next;
    
    node(int val){
      data = val;
      next = NULL;
    }
};

void insert_at_head(node* &head, int val){
  node* new_node = new node(val);
  new_node->next = head;
  head = new_node;
}
void insert_at_tail(node* &head, int val){
  node* new_node = new node(val);
  if(head == NULL){ return insert_at_head(head, val); }
  node* temp = head;
  while(temp->next!=NULL) temp = temp->next;
  temp->next = new_node;
}
void display(node* &head){
  if(head == NULL){ cout<<"NULL (empty)"<<endl; return; }
  node* temp = head;
  while(temp!=NULL){
    cout<<temp->data<<" -> ";
    temp = temp->next;
  }
  cout<<"NULL"<<endl;
}

void even_afer_odd(node* head){
  node* odd_ptr = head;
  node* even_ptr = head->next;
  node* even_start = even_ptr;

  while(odd_ptr->next!=NULL && even_ptr->next!=NULL){
    
    odd_ptr->next = even_ptr->next;
    odd_ptr = odd_ptr->next;
    
    even_ptr->next = odd_ptr->next;
    even_ptr = even_ptr->next;
  }
  odd_ptr->next = even_start;

}

int main(){
  node* head = NULL;
  int i=0,n=7; while(i<n) insert_at_tail(head, ++i);  
  cout<<endl;
  cout<<"list: ";display(head);

  cout<<"# even_afer_odd =>"<<endl;
  even_afer_odd(head);
  cout<<"list: ";display(head);
  cout<<endl;

  return 0;
}