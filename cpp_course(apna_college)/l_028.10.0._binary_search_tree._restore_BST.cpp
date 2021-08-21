#include <bits/stdc++.h>
using namespace std;
struct Node{
  int data;
  struct Node *left;
  struct Node *right;
  Node(int val){
    data = val;
    left = NULL;
    right = NULL;
  }
};
typedef struct Node node;


void calc_pointers(node* root, node** first, node** mid, node** last, node** tn){
  if(root==NULL) return;
  calc_pointers(root->left, first, mid, last, tn);
  if(*tn && root->data<(*tn)->data){
    if(!*first){
      *first = *tn;
      *mid = root;
    }else{
      *last = root;
    }
  }
  *tn = root;
  calc_pointers(root->right, first, mid, last, tn);
}


void swap_node_data(int *a, int *b){
  int temp = *a;
  *a = *b;
  *b = temp;
}

// only 2 nodes are swapped and are violating BST's properties
// you need to find these 2 out of place and swap
void restore_BST(node* root){
  node *first,*mid,*last,*tn;
  first=mid=last=tn=NULL;
  calc_pointers(root, &first, &mid, &last, &tn);
  if(first && last){
    swap_node_data(&(first->data), &(last->data));
  }else if(first && mid){
    swap_node_data(&(first->data), &(mid->data));
  }
}

void inorder_print(node* root){
  if(root==NULL) return;
  inorder_print(root->left);
  cout<<root->data<<" ";
  inorder_print(root->right);
}

int main(){

/*
        6
       /\
      9  3
     /\  \
    1 4  13
*/

  node* root = new node(6);
  root->left = new node(9);
  root->right = new node(3);
  root->left->left = new node(1);
  root->left->right = new node(4);
  root->right->right = new node(13);


  cout<<"inorder: ";inorder_print(root); cout<<endl;
  restore_BST(root);
  cout<<"inorder: ";inorder_print(root); cout<<endl;

/*
     6
    4
   2
  3
*/

  root = new node(6);
  root->left = new node(4);
  root->left->left = new node(2);
  root->left->left->left = new node(3);
  cout<<"inorder: ";inorder_print(root); cout<<endl;
  restore_BST(root);
  cout<<"inorder: ";inorder_print(root); cout<<endl;
  return 0;
}