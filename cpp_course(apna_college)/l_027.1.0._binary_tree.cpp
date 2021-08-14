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

string preorder(node *root, string s){
  if (root == NULL) return s;
  s += to_string(root->data) + " ";
  s += preorder(root->left, "");
  s += preorder(root->right, "");
  return s;
}

string inorder(node *root, string s){
  if (root == NULL) return s;
  s += inorder(root->left, "");
  s += to_string(root->data) + " ";
  s += inorder(root->right, "");
  return s;
}

string postorder(node *root, string s){
  if (root == NULL) return s;
  s += postorder(root->left, "");
  s += postorder(root->right, "");
  s += to_string(root->data) + " ";
  return s;
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

  cout << "preorder : " << preorder(root, "")<<endl;
  // preorder : 1 2 4 5 3 6 7 
  cout << "inorder  : " << inorder(root, "")<<endl;
  // inorder  : 4 2 5 1 6 3 7 
  cout << "postorder: " << postorder(root, "")<<endl;
  // postorder: 4 5 2 6 7 3 1 


  return 0;
}