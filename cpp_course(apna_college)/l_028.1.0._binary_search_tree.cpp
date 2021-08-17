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


node* insert_BST(node* root, int val){
  if(root==NULL) return new node(val);

  if(val<root->data)
    root->left = insert_BST(root->left, val);
  else 
    root->right = insert_BST(root->right, val);
  
  return root;
}

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

node* create_BST(vector<int>v){
  node* root = NULL;
  root = insert_BST(root,v[0]);
  for(int i=1; i<v.size(); i++)
    insert_BST(root, v[i]);
  return root;
}

node* search_in_BST(node* root, int k){
  if(root==NULL) return NULL;
  if(k==root->data) return root;
  if(k<root->data)
    return search_in_BST(root->left, k);
  else 
    return search_in_BST(root->right, k);
}

node* inorder_successor(node* root){
  node* curr = root;
  while(curr && curr->left!=NULL) curr=curr->left;
  return curr;
}

node* delete_in_BST(node* root, int k){
  if(root==NULL) return NULL;
  if(k<root->data)
    root->left = delete_in_BST(root->left, k);
  else if(k>root->data)
    root->right = delete_in_BST(root->right, k);
  else{
    // root->data == k
    if(root->left==NULL && root->right==NULL){
      free(root);
      return NULL;
    }else if(root->left==NULL){
      node* temp = root->right;
      free(root);
      return temp;
    }else if(root->right==NULL){
      node* temp = root->left;
      free(root);
      return temp;
    }else{
      node* temp = inorder_successor(root->right);
      root->data = temp->data;
      root->right = delete_in_BST(root->right, temp->data);
    }
  }
  return root;
}

int main(){
  vector<int>v = {7,8,2,1,5,3,6,9};
/*
        7
       / \
      2   8
     /\    \
    1  5    9
      /\
     3  6
*/

  node *root = create_BST(v);
  cout<<"inorder: "; print_inorder(root); cout<<endl;
  cout<<"preorder: "; print_preorder(root); cout<<endl;


  int k = 2;
  node* s_node = search_in_BST(root, k);
  if(s_node==NULL)
    cout<<"not not found"<<endl;
  else 
    cout<<"node found: "<<s_node->data<<endl;

  delete_in_BST(root, k);
  cout<<"inorder: "; print_inorder(root); cout<<endl;
  cout<<"preorder: "; print_preorder(root); cout<<endl;


  return 0;
}