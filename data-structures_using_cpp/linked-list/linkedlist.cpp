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

//funciton to add a node at the start(or head) of our linkedlist
void insert_at_head(node* &head, int val){
  // create a new local new_node
  node* new_node = new node(val);
  // link the next part of this new_node to the head pointer
  new_node->next = head;
  // update the head pointer to the new_node that we have created.. this make new_node as the start of our linkedlist
  head = new_node;
}

// fucntion to add a node at the end(or tail) of our linkedlist
void insert_at_tail(node* &head, int val){
  // create new node
  node* new_node = new node(val);

  // if the linked list is empty or the the head is null
  if(head == NULL){ return insert_at_head(head, val); }

  // temp node witll traverse to the end of the linked list
  node* temp = head;
  while(temp->next!=NULL) temp = temp->next;
  // add to the next of last node we add out new_node
  temp->next = new_node;
}

//funciton to delete a node at start(or head) of our linedlist
void delete_at_head(node* &head){
  // if liknedlist is empty the exit
  if(head==NULL) return;
  // if liknedlist has only 1 element 
  if(head->next==NULL){ 
    head = NULL; return;
  }

  // update to head to next node
  node* to_delete = head;
  head = head->next;
  delete to_delete;
}

//funciton to delete a node at end(or tail) of our linedlist
void delete_at_tail(node* &head){
  // if liknedlist is empty the exit
  if(head==NULL) return;
  // if liknedlist has only 1 element 
  if(head->next==NULL) return delete_at_head(head);
  
  // traverse the linked list to the second last element
  node* temp = head;
  while(temp->next->next!=NULL)
    temp = temp->next;
  node* to_delete = temp->next;
  temp->next = NULL;
  delete to_delete;
}

//funciton to delete a node by value of our linedlist
void deletion_by_val(node* &head, int val){
  if(head==NULL) return;
  if(head->data==val) return delete_at_head(head);
  node* temp = head;
  while(temp->next->data!=val){
    temp = temp->next;
  }
  node* to_delete = temp->next;
  temp->next = temp->next->next;
  delete to_delete;
}

// funciton to display our linkedlist
void display(node* &head){
  if(head == NULL){ cout<<"NULL (empty)"<<endl; return; }
  // else{ cout<<"not null head=="<<head->data<<endl;}
  node* temp = head;
  while(temp!=NULL){
    cout<<temp->data<<" -> ";
    temp = temp->next;
  }
  cout<<"NULL"<<endl;

}

//search if the key is present in the linkedlist or not
bool search_val(node* head, int key){
  node* temp = head;
  while(temp!=NULL){
    if(temp->data == key) return true;
    temp = temp->next;  
  }
  return false;
}

// get the size of the linkedlist
int get_size(node* head){
  int i=0;
  if(head==NULL) return 0;
  node* temp = head;
  while(temp!=NULL){ temp = temp->next; i++; }
  return i;
}

// array to linked list
void list_from_ar(node* &head, int ar[], int size){
  int i=-1;
  while(++i<size) 
    insert_at_tail(head, ar[i]);
}

//funciton to revesrse the likned list in an iterative fashion
node* reverse_list(node* &head){
  // init 3 node pointers
  node* previous_ptr=NULL;
  node* current_ptr=head;
  node* next_ptr;

  while(current_ptr!=NULL){
    next_ptr = current_ptr->next;

    // point next link of current to the previous node
    current_ptr->next = previous_ptr;
    
    // move all the links forward by 1 step
    previous_ptr = current_ptr;
    current_ptr = next_ptr;
  }
  return previous_ptr;
}

// function to revesrse the linked list in a recursive fashion
node* reverse_list_rec(node* &head){
  // if the linkedlist is empty of has only one element
  if(head==NULL || head->next==NULL) return head;

  // declare a new node the returns the recursive result
  node* new_head = reverse_list_rec(head->next);
  // revesrse the link direction 
  head->next->next = head; // II -> I
  head->next = NULL; // I -> NULL
  return new_head;
}

// funciton to reverse k nodes ( each bunch of k nodes is reversed )
node* reverse_k_nodes(node* &head, int k){
  node* previous_ptr = NULL;
  node* current_ptr = head;
  node* next_ptr;
  
  int count = 0;
  while(current_ptr!=NULL && count<k){
    next_ptr = current_ptr->next;
    current_ptr->next = previous_ptr;
    previous_ptr = current_ptr;
    current_ptr = next_ptr;
    count++;
  }
  if(next_ptr!=NULL)
    head->next = reverse_k_nodes(next_ptr, k);
  return previous_ptr;
}

//funciotn to make a cycle in a linked list from some pos
void make_cycle(node* &head, int pos){
  node* temp = head;
  node* loop_start;
  int count = 1;
  //traverse the end of the loop
  while(temp->next != NULL){
    // at pos store the start pointer of the loop to be made
    if(count==pos) loop_start = temp;
    temp = temp->next;
    count++;
  }
  // lastly, create a loop by attaching last->next to loop_start pointer
  temp->next = loop_start;
}

// funciton to detect cycle in a linked list [ Floyd's hare and tortoise algorithm ]
bool detect_cycle(node* &head){
  node* slow = head;
  node* fast = head;
  // traverse a loop till fast reaches the end or just near end of the list
  // this condiiton is wrt to the singly non looped linked list
  while(fast!=NULL && fast->next!=NULL){
    // move slow pointer by one and fast pointer by 2
    slow = slow->next;
    fast = fast->next->next;
    // if fast and slow meet at some point then its cetatin we were in a loop
    if(fast==slow) return true;
  }
  return false;
}

// function to remove cycle [ Floyd's hare and tortoise algorithm ]
void remove_cycle(node* &head){
  node* slow= head;
  node* fast= head;
  do{
    // move slow by 1 and fast by 2
    slow = slow->next;
    fast = fast->next->next;
  }while(slow!=fast);

  // when they both meet then move fast to the head and slow remains in the same place
  fast = head;
  while(slow->next!=fast->next){
    // now move both pointers to keep moving ny 1
    // till the the point when both point to the same node at a time
    slow = slow->next;
    fast = fast->next;
  }
  //break the cycle by pointing slow node to NULL
  slow->next = NULL;
}

//tests
void test_insert_at_head(){ 
  int d=_d; line_break; while(d--) cout<<'-'; line_break;
  cout<<"## test_insert_at_head => "<<endl;
  node* head = NULL;
  int n = 5;
  int i=0; 
  while(display(head),i<=n) insert_at_head(head, ++i);
  line_break;
}
void test_delete_at_head(){
  int d=_d; line_break; while(d--) cout<<'-'; line_break;
  cout<<"## test_delete_at_head => "<<endl;
  node* head = NULL;
  int n = 5, i=0;
  while(i<n) insert_at_head(head, ++i); 
  while(display(head),get_size(head)) delete_at_head(head); 
  line_break;
}
void test_insert_at_tail(){ 
  int d=_d; line_break; while(d--) cout<<'-'; line_break;
  cout<<"## test_insert_at_tail => "<<endl;
  node* head = NULL;
  int n = 5;int i=0; 
  while(display(head),i<=n) insert_at_tail(head, ++i); 
  line_break;
}
void test_delete_at_tail(){ 
  int d=_d; line_break; while(d--) cout<<'-'; line_break;
  cout<<"## test_delete_at_tail => "<<endl;
  node* head = NULL;
  int n = 5;
  int i=0; 
  while(i<=n) insert_at_tail(head, ++i); 
  while(display(head),get_size(head)) delete_at_tail(head); 
  line_break;
}
void test_deletion_by_val(){ 
  int d=_d; line_break; while(d--) cout<<'-'; line_break;
  cout<<"## test_deletion_by_val => "<<endl;
  node* head=NULL;
  int key=2;
  int ar[4] = {1, 2, 3, 4};
  list_from_ar(head, ar, 4);
  cout<<"Before: "; display(head);
  cout<<"Deleting key= "<<key<<endl;
  deletion_by_val(head, key);
  cout<<"After : "; display(head);
  line_break;
}
void test_search_by_val(){ 
  int d=_d; line_break; while(d--) cout<<'-'; line_break;
  cout<<"## test_search_by_val => "<<endl;
  node* head=NULL;
  int ar[4] = {1, 2, 3, 4};
  list_from_ar(head, ar, 4);
  cout<<"LinkedList: "; display(head);
  int key=2;
  cout<<"Search key "<<key<<"=>"<<(search_val(head, key)?" present":" not present")<<endl;
  key = 5;
  cout<<"Search key "<<key<<"=>"<<(search_val(head, key)?" present":" not present")<<endl;
}
void test_reverse_list(){
  int d=_d; line_break; while(d--) cout<<'-'; line_break;
  cout<<"## test_reverse_list => "<<endl;
  node* head=NULL; int l=6;
  int ar[l] = {1, 2, 3, 4, 5, 6};
  list_from_ar(head, ar, l);
  cout<<"list: "; display(head);
  node* reverse = reverse_list(head);
  cout<<"rev : "; display(reverse);
  line_break;
}
void test_reverse_list_recursive(){
  int d=_d; line_break; while(d--) cout<<'-'; line_break;
  cout<<"## test_reverse_list_recursive => "<<endl;
  node* head=NULL; int l=6;
  int ar[l] = {1, 2, 3, 4, 5, 6};
  list_from_ar(head, ar, l);
  cout<<"list: "; display(head);
  node* reverse = reverse_list_rec(head);
  cout<<"rev : "; display(reverse);
  line_break;
}
void test_reverse_k_nodes(){
  int d=_d; line_break; while(d--) cout<<'-'; line_break;
  cout<<"## test_reverse_k_nodes => "<<endl;
  node* head=NULL; int l=10; int k=3;
  int ar[l] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  list_from_ar(head, ar, l);
  cout<<"list  : "; display(head);
  node* reverse = reverse_k_nodes(head, k);
  cout<<"rev_k : "; display(reverse);
  line_break;
}
void test_remove_cycle(){
  int d=_d; line_break; while(d--) cout<<'-'; line_break;
  cout<<"## test_remove_cycle => "<<endl;
  node* head = NULL; int i=0, n=6;
  while(i<n) insert_at_tail(head, ++i);
  cout<<"list: "; display(head);
  make_cycle(head, 3);
  int cy=15; node* temp = head; cout<<"cycle: "; do cout<<temp->data<<" -> "; while(temp=temp->next, --cy); cout<<"looped"<<endl;
  cout<<"cycle is "<<(detect_cycle(head)?"present":" not present")<<endl;
  remove_cycle(head);
  cout<<"rem_cycle :"; display(head); line_break;
}

int main(){
  // node* head = NULL;
  // int l= 6;
  // int ar[l] = {1, 2, 3, 4, 5, 6};
  // list_from_ar(head, ar, l);
  // display(head);

  test_insert_at_head();
  test_delete_at_head();
  test_insert_at_tail();
  test_delete_at_tail();
  test_deletion_by_val();
  test_search_by_val();
  test_reverse_list();
  test_reverse_list_recursive();
  test_reverse_k_nodes();
  test_remove_cycle();
  
  return 0;
}