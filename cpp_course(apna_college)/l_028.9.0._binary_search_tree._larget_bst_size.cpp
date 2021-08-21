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

struct Info{
  int size;
  int max;
  int min;
  int ans;
  bool is_BST;
};
 
Info largest_BST_in_BT(Node* root){
  if(root==NULL)
    return {0, INT_MIN, INT_MAX, 0, true};
  if(root->left==NULL && root->right==NULL)
    return {1, root->data, root->data, 1, true};
  
  Info left_Info = largest_BST_in_BT(root->left);
  Info right_Info = largest_BST_in_BT(root->right);
  Info current_Info;
  current_Info.size = left_Info.size+right_Info.size+1;
  if(
    left_Info.is_BST==true &&
    right_Info.is_BST==true &&
    root->data>left_Info.max &&
    root->data<right_Info.min
  ){
    current_Info.min = min(root->data, min(left_Info.min,right_Info.min));
    current_Info.max = max(root->data, max(left_Info.max,right_Info.max));
    current_Info.ans = current_Info.size;
    current_Info.is_BST = true;
    return current_Info;
  }
  current_Info.ans = max(left_Info.ans, right_Info.ans);
  current_Info.is_BST = false;
  return current_Info;

}

int main(){

/*
       15
       /\
     20 30
    /
   5
*/

  node* root = new node(15);
  root->left = new node(20);
  root->right = new node(30);
  root->left->left = new node(5);

  cout<<"largest BST in BT: "<< largest_BST_in_BT(root).ans<<endl;


  return 0;
}