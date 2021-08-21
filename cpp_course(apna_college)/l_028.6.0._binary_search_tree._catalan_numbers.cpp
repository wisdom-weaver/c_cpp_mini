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

void inorder_print(node*root ){
  if(root==NULL) return;
  inorder_print(root->left);
  cout<<root->data<<" ";
  inorder_print(root->right);
}
void preorder_print(node*root ){
  if(root==NULL) return;
  cout<<root->data<<" ";
  preorder_print(root->left);
  preorder_print(root->right);
}

int catalan(int n){
  if(n==1||n==0) return 1;
  int s = 0;
  for(int i=0;i<n;i++)
    s += catalan(i)*catalan(n-i-1);
  return s;
}

vector<node*> possible_BSTs(int start, int end){
  vector<node*> trees;
  if(start>end){
    trees.push_back(NULL);
    return trees;
  }
  for(int i=start;i<=end;i++){
    vector<node*> left_subtrees = possible_BSTs(start, i-1);
    vector<node*> right_subtrees = possible_BSTs(i+1, end);
    for(int j=0;j<left_subtrees.size();j++){
      node* left = left_subtrees[j];
      for(int k=0;k<right_subtrees.size();k++){
        node* right = right_subtrees[k];
        node* node = new Node(i);
        node->left = left;
        node->right = right;
        trees.push_back(node);
      }
    }
  }
  return trees;
}

int main(){
  int n = 3;
  for(int i=0;i<=n;i++) cout<<"catalan("<<i<<"): "<<catalan(i)<<endl;
  
  vector<node*> trees = possible_BSTs(1,3);
  for(int i=0; i<trees.size();i++){
    cout<<"preorder "<<i<<": "; preorder_print(trees[i]); cout<<"\t";
    cout<<"inorder  "<<i<<": "; inorder_print(trees[i]); cout<<endl;
  }

  return 0;
}