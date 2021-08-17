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

bool get_path(node* root, int key, vector<int>&path){
  if(root==NULL) return false;
  path.push_back(root->data);
  if(root->data==key) return true;
  if(get_path(root->left,key,path) || get_path(root->right,key,path))
    return true;
  else {
    path.pop_back();
    return false;
  }
}

int LCA(node* root, int n1, int n2){
  vector<int> path1, path2;
  if(!get_path(root,n1,path1) || !get_path(root, n2, path2))
    return -1;
  
  int pc;
  for(pc=0; pc<path1.size() && path2.size(); pc++)
    if(path1[pc] != path2[pc])
      break;
  
  return path1[pc-1];
}

// Method-2
node* LCA2(node* root, int n1, int n2){
  if(root==NULL) return NULL;
  if(root->data==n1 || root->data==n2) return root;
  
  node* left = LCA2(root->left, n1, n2);
  node* right = LCA2(root->right, n1, n2);

  if(left!=NULL && right!=NULL) return root;
  if(left==NULL && right==NULL) return NULL;
  if(left!=NULL) return left;
  if(right!=NULL) return right;
  return NULL;
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

  int lca = LCA(root, 8, 5);
  if(lca!=-1) cout<<"lca:"<<lca<<endl;
  else cout<<"lca: NULL"<<endl;

  node* lca2 = LCA2(root, 8, 5);
  if(lca2) cout<<"lca:"<<lca2->data<<endl;
  else cout<<"lca: NULL"<<endl;

  return 0;
}