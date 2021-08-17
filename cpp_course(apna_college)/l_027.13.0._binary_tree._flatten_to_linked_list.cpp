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

void flatten(node* root){
  if(root==NULL) return;
  if(root->left==NULL && root->right==NULL) return;
  if(root->left!=NULL){
    flatten(root->left);
    node* temp = root->right;
    root->right = root->left;
    root->left = NULL;

    node* right_tail=root->right;
    while(right_tail->right!=NULL) right_tail=right_tail->right;

    right_tail->right = temp;
  }
  if(root->right!=NULL)
    flatten(root->right);
}

void display_flattened(node* root){
  node* temp=root;
  cout<<"flattened: ";
  while(temp!=NULL){
    cout<<temp->data<<" ";
    temp = temp->right;
  }
  cout<<endl;
}

int main(){
  node *root = new node(1);
  root->left = new node(2);
  root->right = new node(3);

  root->left->left = new node(4);
  root->left->right = new node(5);

  root->right->left = new node(6);
  root->right->right = new node(7);
  /*
       1
     /  \
    2    3
   /\   / \
  4  5 6  7
*/

  flatten(root);
  display_flattened(root);

  root = new node(4);
  root->left = new node(9);
  root->right = new node(5);

  root->left->left = new node(1);
  root->left->right = new node(3);
  root->right->right = new node(6);

/*
       4
     /  \
    9    5
   / \    \
  1   3    6
*/
  flatten(root);
  display_flattened(root);

  return 0;
}