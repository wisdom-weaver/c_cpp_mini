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

void right_view(node* root){
  if(!root) return;
  queue<node*> q;
  q.push(root);

  while(!q.empty()){
    int size = q.size();
    for(int i=0;i<size;i++){
      node* curr = q.front(); q.pop();
      if(i==size-1) cout<<curr->data<<" ";

      if(curr->left) q.push(curr->left);
      if(curr->right) q.push(curr->right);
    }
  }
}

void left_view(node* root){
  if(!root) return;
  queue<node*> q;
  q.push(root);

  while(!q.empty()){
    int size = q.size();
    for(int i=0;i<size;i++){
      node* curr = q.front(); q.pop();
      if(i==0) cout<<curr->data<<" ";

      if(curr->left) q.push(curr->left);
      if(curr->right) q.push(curr->right);
    }
  }
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
  cout<<"right_view: ";
  right_view(root);
  cout<<endl;
  cout<<"left_view: ";
  left_view(root);
  cout<<endl;

  return 0;
}