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


void print_inorder(node* root){
  if(root==NULL) return;
  print_inorder(root->left);
  cout<<root->data<<" ";
  print_inorder(root->right);
}
void print_preorder(node* root){
  if(root==NULL) return;
  cout<<root->data<<" ";
  print_preorder(root->left);
  print_preorder(root->right);
}

node* create_BST_from_preorder(vector<int>preorder, int* preorder_idx, int min, int max){
  int n = preorder.size();
  if(*preorder_idx>=n) return NULL;
  int key = preorder[*preorder_idx];

  node* root = NULL;
  if(key>min && key<max){
    root = new node(key);
    *preorder_idx = *preorder_idx+1;
    if(*preorder_idx<n)
      root->left = create_BST_from_preorder(preorder, preorder_idx, min, key);
    if(*preorder_idx<n)
      root->right = create_BST_from_preorder(preorder, preorder_idx, key, max);
  }
  return root;
}

node* create_BST_from_preorder(vector<int>preorder){
  int preorder_idx = 0;
  int min = INT_MIN;
  int max = INT_MAX;
  node* root = create_BST_from_preorder(preorder, &preorder_idx, min,max);
  return root;
}


int main(){
  vector<int>preorder = {10,2,1,13,11};

  node *root = create_BST_from_preorder(preorder);
  cout<<"inorder: "; print_inorder(root); cout<<endl;
  cout<<"preorder: "; print_preorder(root); cout<<endl;

  return 0;
}