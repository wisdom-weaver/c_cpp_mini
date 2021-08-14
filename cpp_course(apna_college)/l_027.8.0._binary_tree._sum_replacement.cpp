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


void sum_replacement(node* root){
  if(root==NULL) return;
  sum_replacement(root->left);
  sum_replacement(root->right);
  int sum =0;
  if(root->left!=NULL) sum+=root->left->data;
  if(root->right!=NULL) sum+=root->right->data;
  root->data += sum;
}

void preorder_print(node* root){
  if(root==NULL) return;
  cout<<root->data<<" ";
  preorder_print(root->left);
  preorder_print(root->right);
}

int main()
{
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

  // sum_replacement(root);
  cout<<"Tree: \n";
  preorder_print(root);
  cout<<endl;

  sum_replacement(root);

  cout<<"sum replaced: \n";
  preorder_print(root);
  cout<<endl;
  return 0;
}