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

void nodes_at_distK_sub(node* root, int k){
  if(root==NULL || k<0) return;
  if(k==0){ cout<<root->data<<" "; return; }

  nodes_at_distK_sub(root->left, k-1);
  nodes_at_distK_sub(root->right, k-1);
}

int nodes_at_distK(node* root, node* target, int k){
  if(root==NULL) return -1;
  if(root==target) {
    nodes_at_distK_sub(root, k);
    return 0;
  }
  
  int dl = nodes_at_distK(root->left, target, k);
  if(dl!=-1){
    if(dl+1==k)
      cout<<root->data<<" ";
    else 
      nodes_at_distK_sub(root->right, k-dl-2);
    return 1+dl;
  }

  int dr = nodes_at_distK(root->right, target, k);
  if(dr!=-1){
    if(dr+1==k)
      cout<<root->data<<" ";
    else 
      nodes_at_distK_sub(root->left, k-dr-2);
    return 1+dr;
  }

  return -1;

}

int main(){
  node *root = new node(1);
  root->left = new node(2);
  root->right = new node(3);

  root->left->left = new node(4);
  root->left->right = new node(5);

  root->right->left = new node(6);
  root->right->right = new node(7);
  
  root->left->left->left = new node(8);
  root->left->left->right = new node(9);
  /*
        1
      /  \
     2    3
    /\   / \
   4  5 6  7
  / \
 8  9
*/

  nodes_at_distK(root, root->left, 2);

  return 0;
}