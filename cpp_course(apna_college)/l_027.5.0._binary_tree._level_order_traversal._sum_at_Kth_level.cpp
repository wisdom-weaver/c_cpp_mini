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

void print_level_order(node* root){
  if(root==NULL) return;
  int sum=0;
  queue<node*> q;
  q.push(root);
  q.push(NULL);
  while(!q.empty()){
    node* n = q.front();
    q.pop();
    if(n!=NULL){
      cout<<n->data<<" ";
      sum+=n->data;
      if(n->left) q.push(n->left);
      if(n->right) q.push(n->right);
    }else if(!q.empty()){
      q.push(NULL);
    }

    if(!q.empty() && q.front()==NULL){
      cout<<" => "<<sum<<endl;
      sum=0;
    }

  }
}

int get_Kth_level_sum(node*root , int k){
  if(root==NULL) return -1;
  int level=0, sum=0;
  queue<node*> q;
  q.push(root);
  q.push(NULL);

  while(!q.empty()){
    node* n = q.front();
    q.pop();
    if(n!=NULL){
      if(level==k) sum+=n->data;
      if(n->left) q.push(n->left);
      if(n->right) q.push(n->right);
    }else if(!q.empty()){
      q.push(NULL);
      level++;
    }
  }

  return sum;
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

  print_level_order(root);

  int k=1;
  cout<<"sum at level K="<<k<<": "<< get_Kth_level_sum(root, k)<<endl;
  k=2;
  cout<<"sum at level K="<<k<<": "<< get_Kth_level_sum(root, k)<<endl;

  return 0;
}