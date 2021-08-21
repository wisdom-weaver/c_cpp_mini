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

node* create_balanced_BST_from_sorted(vector<int>ar, int start, int end){
  if(start>end) return NULL;
  int mid = (start+end)/2;
  node* root = new Node(ar[mid]);
  root->left = create_balanced_BST_from_sorted(ar, start, mid-1);
  root->right = create_balanced_BST_from_sorted(ar, mid+1, end);
  return root;
}

node* create_balanced_BST_from_sorted(vector<int>ar){
  return create_balanced_BST_from_sorted(ar, 0, ar.size()-1);
}

int main(){
  vector<int>ar = {10,20,30,40,50};
  node *root = create_balanced_BST_from_sorted(ar);
  cout<<"inorder: "; inorder_print(root); cout<<endl;
  cout<<"preorder: "; preorder_print(root); cout<<endl;

  return 0;
}