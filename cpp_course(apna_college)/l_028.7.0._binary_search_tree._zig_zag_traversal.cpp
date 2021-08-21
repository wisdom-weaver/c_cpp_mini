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

void inorder_print(node*root ){
  if(root==NULL) return;
  inorder_print(root->left);
  cout<<root->data<<" ";
  inorder_print(root->right);
}
void preorder_print(node*root ){
  if(root==NULL) return;
  cout<<root->data<<" ";
  preorder_print(root->left);
  preorder_print(root->right);
}

void zig_zag_traversal(node* root){
  if(root==NULL) return;
  bool left_to_right=true;
  stack<node*>curr_level;
  stack<node*>next_level;
  curr_level.push(root);
  
  while(!curr_level.empty()){
    node* temp = curr_level.top(); curr_level.pop();
    if(temp!=NULL){
      cout<<temp->data<<" ";
      if(left_to_right==true){
        if(temp->left) next_level.push(temp->left);
        if(temp->right) next_level.push(temp->right);
      }else{
        if(temp->right) next_level.push(temp->right);
        if(temp->left) next_level.push(temp->left);
      }
    }
    if(curr_level.empty()){
      left_to_right=!left_to_right;
      swap(curr_level, next_level);
    }
  }
}


int main(){
  node* root = new node(12);
  root->left = new node(9);
  root->right = new node(15);
  root->left->left = new node(5);
  root->left->right = new node(10);
  root->right->left = new node(14);
/*
      12
     /  \
    9   15
   /\   /
  5 10 14
*/

  cout<<"zig_zag: "; zig_zag_traversal(root); cout<<endl;
  

  return 0;
}