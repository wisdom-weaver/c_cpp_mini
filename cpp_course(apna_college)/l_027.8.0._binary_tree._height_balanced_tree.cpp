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


int tree_height(node*root){
  if(root==NULL) return 0;
  return max(tree_height(root->left),tree_height(root->right))+1;
}

// left tree height and right tree height difference is not more than 1
bool is_balanced_height_tree(node* root){
  if(root==NULL) return true;
  if(!is_balanced_height_tree(root->left)) return false;
  if(!is_balanced_height_tree(root->right)) return false;

  int lh = tree_height(root->left);
  int rh = tree_height(root->right);
  return (abs(lh-rh)<=1);
}

bool is_balanced_height_tree_opt(node* root, int* height){
  if(root==NULL) return true;
  int lh=0,rh=0;

  if(!is_balanced_height_tree_opt(root->left, &lh)) return false;
  if(!is_balanced_height_tree_opt(root->right, &rh)) return false;

  *height = max(lh,rh)+1;

  return (abs(lh-rh)<=1);
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

  cout<<is_balanced_height_tree(root)<<endl;
  int h1 = 0;
  cout<<is_balanced_height_tree_opt(root,&h1)<<endl;

  root->left->left->left = new node(8);
  root->left->left->left->left = new node(9);
    /*
        1
       /  \
      2    3
     /\   / \
    4  5 6  7
   /
  8
 /
9
*/
  cout<<is_balanced_height_tree(root)<<endl;
  int h = 0;
  cout<<is_balanced_height_tree_opt(root,&h)<<endl;

  return 0;
}