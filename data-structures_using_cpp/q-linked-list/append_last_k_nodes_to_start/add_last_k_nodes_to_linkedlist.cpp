#include <iostream>
using namespace std;
#define line_break (cout<<endl)
#define line_break_n(n) {int sn=max(0,n-1); do line_break; while(sn--);} 
#define _d 100;

class node{
  public: 
    int data;
    node* next=NULL;
  
    node(int val){
      data = val;
      next = NULL;
    }
};

int get_size(node* &head){
  int i=0;
  if(head==NULL) return 0;
  node* temp = head;
  while(temp!=NULL){ temp = temp->next; i++; }
  return i;
}
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

node* append_last_k_nodes(node* &head, int k){
  node* new_head;
  node* new_tail;
  node* tail = head;
  
  int l = get_size(head);
  k = k%l; // if k is larger than l
  int pos= l-k; // get the position at wich we have to break the list

  int counter=1;
  while(tail->next!=NULL){
    // node at pos becomes the tail of our new list
    if(counter == pos) new_tail = tail;
    // node next to pos becomes the head of our new list
    if(counter == pos+1) new_head = tail;

    tail = tail->next;
    counter++;
  }
  // join the broken parts of our linked list
  new_tail->next = NULL; // nothing ahead out of out new tail
  tail->next = head; // last element of the current list pointes to our current head;

  return new_head;
}

int main(){
  node* head = NULL;
  int n=7; int i=0; while(i<n)insert_at_tail(head, ++i);
  cout<<"linked list:    = ";display(head);

  int k=10;
  node* ap_k_list = append_last_k_nodes(head, k);
  cout<<"append_k_nodes: = ";display(ap_k_list);

  return 0;
}