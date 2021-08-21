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

bool identical_BSTs(node* r1, node* r2){
  if(r1==NULL && r2==NULL) return true;
  if(r1==NULL || r2==NULL) return false;
  if(r1->data != r2->data) return false;
  return identical_BSTs(r1->left,r2->left) && identical_BSTs(r1->right,r2->right);
}

int main(){
  node* r1 = new node(12);
  r1->left = new node(9);
  r1->right = new node(15);
  r1->left->left = new node(5);
  r1->left->right = new node(10);
  r1->right->left = new node(14);

  node* r2 = new node(12);
  r2->left = new node(9);
  r2->right = new node(15);
  r2->left->left = new node(4);
  r2->left->right = new node(10);
  r2->right->left = new node(14);

  node* r3 = new node(12);
  r3->left = new node(9);
  r3->right = new node(15);
  r3->left->left = new node(4);
  r3->left->right = new node(10);
  r3->right->left = new node(14);

  cout<<"identical_BSTs: "<<identical_BSTs(r1, r2)<<endl;
  cout<<"identical_BSTs: "<<identical_BSTs(r2, r3)<<endl;
  
  return 0;
}