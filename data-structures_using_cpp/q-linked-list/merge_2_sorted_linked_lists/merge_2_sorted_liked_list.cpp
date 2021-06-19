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
  node* temp = head; int exp=20;
  while(temp!=NULL && --exp){
    cout<<temp->data<<" -> ";
    temp = temp->next;
  }
  if(exp==0) cout<<"looped"<<endl;
  else cout<<"NULL"<<endl;

}
void list_from_ar(node* &head, int ar[], int size){
  int i=-1;
  while(++i<size) 
    insert_at_tail(head, ar[i]);
}

// Function to merger 2 sorted linked lists
node* merge(node* &head1, node* &head2){
  node* dummy_node = new node(-1);
  node* p1 = head1;
  node* p2 = head2;
  node* p3 = dummy_node;
  while(p1!=NULL && p2!=NULL){
    // compare the data and add them to p3 respectively
    if(p1->data<p2->data){
      p3->next=p1;
      p1 = p1->next;
    }else{
      p3->next=p2;
      p2 = p2->next;
    }
    p3 = p3->next;
  }
  // add left over nodes of p1
  while(p1!=NULL){
    p3->next=p1;
    p1=p1->next;
    p3=p3->next;
  }
  // add left over nodes of p2
  while(p2!=NULL){
    p3->next=p2;
    p2=p2->next;
    p3=p3->next;
  }
  return dummy_node->next;
}

// Function to merger 2 sorted linked lists in recursive fashion
node* merge_rec(node* &head1, node* &head2){
  // if we exhaust list-1
  if(head1==NULL) return head2;
  // if we exhaust list-2
  if(head2==NULL) return head1;

  node* result;
  if(head1->data < head2->data){
    result = head1;
    result->next = merge_rec(head1->next, head2);
  }else {
    result = head2;
    result->next = merge_rec(head1, head2->next);
  }
  return result;
}

int main(){
  node* head1 = NULL;
  int n, i;
  int ar1[]={1, 3,4,6,10};
  list_from_ar(head1, ar1, sizeof(ar1)/sizeof(ar1[0]));
  
  node* head2 = NULL;
  int ar2[]={2,3,5};
  list_from_ar(head2, ar2, sizeof(ar2)/sizeof(ar2[0]));

  cout<<"linked list1:      ";display(head1);
  cout<<"linked list2:      ";display(head2);
  
  // node* merged_list = merge(head1, head2);
  // cout<<"merged list[itt]:  ";display(merged_list);
  node* merged_list_rec = merge_rec(head1, head2);
  cout<<"merged list[rec]:  ";display(merged_list_rec);
  return 0;
}