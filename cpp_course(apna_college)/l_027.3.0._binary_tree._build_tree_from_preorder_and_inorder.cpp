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

int search(int inorder[], int start, int end, int curr){
  for(int i=start; i<=end; i++)
    if(inorder[i]==curr)
      return i;
  return -1;
}

node* build_tree_prein(int preorder[], int inorder[], int start, int end){
  static int idx = 0;
  if(start>end) return NULL;
  
  int curr = preorder[idx];
  idx++;
  node* n = new node(curr);
  if(start == end) return n;

  int pos = search(inorder, start, end, curr);
  n->left = build_tree_prein(preorder, inorder, start, pos-1);
  n->right = build_tree_prein(preorder, inorder, pos+1, end);
  return n;
}

void inorder_print(node*root){
  if(root==NULL) return;
  inorder_print(root->left);
  cout<<root->data<<" ";
  inorder_print(root->right);
}

int main()
{
  cout<<"build tree from preorder and inorder: "<<endl;
  int n=5;
  int preorder[] = {1,2,4,3,5};
  int inorder[] = {4,2,1,5,3};
  node* tree = build_tree_prein(preorder, inorder, 0, n-1);;
  inorder_print(tree);

  /*
       1
     /  \
    2    3
   /\   / \
  4  5 6  7
*/

  return 0;
}