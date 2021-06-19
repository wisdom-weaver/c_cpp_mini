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
void make_intersection(node* &head1, node* &head2, int pos){
  node* temp1=head1; pos=pos-1;
  while(temp1->next!=NULL && pos--) temp1 = temp1->next;
  cout<<temp1->data<<endl;
  node* temp2=head2;
  while(temp2->next!=NULL) temp2 = temp2->next;
  temp2->next = temp1;
}
void list_from_ar(node* &head, int ar[], int size){
  int i=-1;
  while(++i<size) 
    insert_at_tail(head, ar[i]);
}

// Function to get intersection point value of 2 linked-lists
int intersection(node* &head1, node* &head2){
  int l1 = get_size(head1);
  int l2 = get_size(head2);
  node* ptr1; node* ptr2;
  int st, i=0;
  
  if(l1>l2){ ptr1=head1; ptr2=head2; st=l1-l2; }
  else{ ptr1=head2; ptr2=head1; st=l2-l1; }
  
  while(st--) ptr1 = ptr1->next;
  while(ptr1!=NULL && ptr2!=NULL){
    if(ptr1 == ptr2) return ptr1->data;
    ptr1 = ptr1->next;
    ptr2 = ptr2->next;
  }
  return -999;
}


int main(){
  node* head1 = NULL;
  int n, i;
  int ar1[]={1,2,3,4,5,6};
  list_from_ar(head1, ar1, sizeof(ar1)/sizeof(ar1[0]));
  
  node* head2 = NULL;
  int ar2[]={7,8};
  list_from_ar(head2, ar2, sizeof(ar2)/sizeof(ar2[0]));

  make_intersection(head1, head2, 5);

  cout<<"linked list1:    = ";display(head1);
  cout<<"linked list2:    = ";display(head2);

  // get intersection point of 2 linkedlists
  cout<<"intersection: => "<<intersection(head2, head1)<<endl;
  return 0;
}