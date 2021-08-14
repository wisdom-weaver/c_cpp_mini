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

node* build_tree_postin(int postorder[], int inorder[], int start, int end){
  static int idx = end;
  if(start>end) return NULL;
  
  int curr = postorder[idx];
  idx--;
  node* n = new node(curr);
  if(start == end) return n;

  int pos = search(inorder, start, end, curr);
  n->right = build_tree_postin(postorder, inorder, pos+1, end);
  n->left = build_tree_postin(postorder, inorder, start, pos-1);
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
  cout<<"build tree from postorder and inorder: "<<endl;
  int n=5;
  int postorder[] = {4,2,5,3,1};
  int inorder[] = {4,2,1,5,3};
  node* tree = build_tree_postin(postorder, inorder, 0, n-1);;
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