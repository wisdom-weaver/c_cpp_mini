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

node* LCA(node* root, int n1, int n2){
  if(root==NULL) return NULL;
  if(root->data==n1 || root->data==n2) return root;
  
  node* left = LCA(root->left, n1, n2);
  node* right = LCA(root->right, n1, n2);

  if(left!=NULL && right!=NULL) return root;
  if(left==NULL && right==NULL) return NULL;
  if(left!=NULL) return left;
  if(right!=NULL) return right;
  return NULL;
}

int find_dist(node* root, int k, int d){
  if(root==NULL) return -1;
  if(root->data==k) return d;

  int left_d = find_dist(root->left,k,d+1);
  if(left_d!=-1) return left_d;
  int right_d = find_dist(root->right,k,d+1);
  if(right_d!=-1) return right_d;
  return -1;
}

int distance_bw_nodes(node* root, int n1, int n2){
  node* lca = LCA(root, n1, n2);
  if(lca==NULL) return -2;
  int d1 = find_dist(lca, n1, 0);
  int d2 = find_dist(lca, n2, 0);
  return d1+d2;
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

  cout<<"distance_bw_nodes 4 5: "<<distance_bw_nodes(root,4,5)<<endl;
  cout<<"distance_bw_nodes 4 7: "<<distance_bw_nodes(root,4,7)<<endl;

  return 0;
}