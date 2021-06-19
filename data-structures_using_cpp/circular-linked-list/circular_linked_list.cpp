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

void display(node* &head){
  node* temp = head;
  if(head==NULL){ cout<<"NULL"<<endl; return; }
  do{
    cout<<temp->data<<" -> ";
    temp = temp->next;
  } while(temp != head);
    
  cout<<"head"<<endl;
}


void insert_at_head(node* &head, int val){
  node* new_node = new node(val);
  // if there is an empty list then make a node that points next to itself thus making it cylcic
  if(head==NULL){
    new_node->next = new_node;
    head = new_node;
    return;
  }
  // traverse the end of the list
  node* temp = head;
  while(temp->next!=head)
    temp = temp->next;
  temp->next = new_node;
  new_node->next = head;
  head = new_node;
}

void insert_at_tail(node* &head, int val){
  if(head==NULL) return insert_at_head(head, val);
  node* new_node = new node(val);
  node* temp = head;
  // to reach the last node we see if the node points back to the head node
  while(temp->next!=head){
    temp = temp->next;
  }
  temp->next = new_node;
  new_node->next = head;
}

void deletion_at_head(node* &head){
  // only one node present
  if(head == NULL){ return; }
  if(head->next == head){ head=NULL; return; }
  
  node* temp = head;
  while(temp->next!=head) 
    temp = temp->next;

  node* to_delete = head;
  temp->next = head->next;
  head = head->next;
  delete to_delete;
}

void deletion_at_pos(node* &head, int pos){
  if(pos==0) return deletion_at_head(head);;

  node* temp = head;
  int counter = 0;
  while(++counter!=pos)
    temp = temp->next;
  node* to_delete = temp->next;
  // skip next node and point to next next node
  temp->next = temp->next->next;
  delete to_delete;
}


int main(){
  node* head = NULL;
  int n, i;
  i=0; n=6; while(i<n) insert_at_tail(head, i++);
  display(head);
  // i=i; n=6; while(i<n) insert_at_head(head, ++i);
  // display(head);
  
  int pos =4; cout<<"deleting at [0-indexing] pos= "<<pos<<endl;
  deletion_at_pos(head,pos); 
  display(head);
  
  
  pos =0; cout<<"deleting at [0-indexing] pos= "<<pos<<endl;
  deletion_at_pos(head,pos); 
  display(head);

  cout<<"deleting at head: "<<endl;
  deletion_at_head(head); display(head);
  deletion_at_head(head); display(head);
  deletion_at_head(head); display(head);
  deletion_at_head(head); display(head);
  deletion_at_head(head); display(head);
  deletion_at_head(head); display(head);
  return 0;
}