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


bool is_valid_BST(node* root){
  cout<<"b";
  if(root==NULL) return true;
  if(root->left)
    if(! (root->data > root->left->data)) return false;
  if(root->right)
    if(! (root->data < root->right->data)) return false;
  return is_valid_BST(root->left) && is_valid_BST(root->right);
}

bool is_valid_BST(node*root, node* min_alw, node* max_alw){
  cout<<"a";
  if(root==NULL) return true;
  if(min_alw!=NULL && root->data<=min_alw->data) return false;
  if(max_alw!=NULL && root->data>=max_alw->data) return false;
  bool left_valid = is_valid_BST(root->left, min_alw, root);
  bool right_valid = is_valid_BST(root->right, root, max_alw);
  return left_valid && right_valid;
}

int main(){
  vector<int>preorder = {10,2,1,13,11};

  node *root = new node(3);
  root->left = new node(2);
  root->right = new node(4);

  cout<<"is_valid_BST: "<<is_valid_BST(root)<<endl;
  cout<<"is_valid_BST: "<<is_valid_BST(root, NULL, NULL)<<endl;

  return 0;
}