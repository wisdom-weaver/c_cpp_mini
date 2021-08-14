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

int nodes_count(node* root){
  if(root==NULL) return 0;
  return nodes_count(root->left) + 1 + nodes_count(root->right);
}

int sum_nodes(node* root){
  if(root==NULL) return 0;
  return sum_nodes(root->left) + root->data + sum_nodes(root->right);
}

int tree_height(node* root){
  if(root==NULL) return 0;
  int left_height = tree_height(root->left);
  int right_height = tree_height(root->right);
  return max(left_height, right_height)+1;
}

// distance between 2 farthest leaf nodes
int tree_diameter(node* root){
  if(root==NULL) return 0;
  int l_height = tree_height(root->left);
  int r_height = tree_height(root->right);
  int curr_diameter = l_height + r_height + 1;
  int l_diameter = tree_diameter(root->left);
  int r_diameter = tree_diameter(root->right);
  return max(
    curr_diameter,
    max(l_diameter,r_diameter)
  );
}

int tree_diameter_opm(node* root, int* height){
  if(root==NULL){
    *height = 0;
    return 0;
  }
  int lh=0, rh=0;
  int l_diameter = tree_diameter_opm(root->left, &lh);
  int r_diameter = tree_diameter_opm(root->right, &rh);
  int curr_diameter = lh+rh+1;
  *height = max(lh,rh+1);
  return max(curr_diameter, max(l_diameter, r_diameter));
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

  cout<<"nodes_count: "<< nodes_count(root)<<endl;
  cout<<"sum_nodes: "<< sum_nodes(root)<<endl;
  cout<<"tree_height: "<< tree_height(root)<<endl;
  cout<<"tree_diameter: "<< tree_diameter(root)<<endl;
  int height = 0; 
  cout<<"tree_diameter: "<< tree_diameter_opm(root, &height)<<endl;

  return 0;
}