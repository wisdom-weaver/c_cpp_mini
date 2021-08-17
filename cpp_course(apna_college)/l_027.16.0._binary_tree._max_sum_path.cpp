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

int max_sum_path(node* root, int& ans){
  if(root==NULL) return 0;
  int sum_l = max_sum_path(root->left, ans);
  int sum_r = max_sum_path(root->right, ans);
  int val = root->data;
  int node_max = max(
    max(val, sum_l+sum_r+val),
    max(sum_r+val, sum_l+val)
  );
  ans = max(ans, node_max);
  int single_path_sum = max(val, max(val+sum_l, val+sum_r));
  return single_path_sum;
}

int max_sum_path(node* root){
  int ans = 0;
  max_sum_path(root, ans);
  return ans;
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

  cout<<"max_sum_path: "<<max_sum_path(root);

  return 0;
}