#include <bits/stdc++.h>
using namespace std;

#define pii pair<int, int>
#define vi vector<int>
#define vii vector<pii>
#define ff first
#define ss second
#define rep(i, a, b) for (int i = a; i < b; i++)

struct node{
  int data;
  node* left;
  node* right;
  node(int val){
    data = val;
    left = right = NULL;
  }
};

void get_vertical_order(node*root, int h_dis, map<int,vi>&mp){
  if(root==NULL) return;
  mp[h_dis].push_back(root->data);
  get_vertical_order(root->left, h_dis-1, mp);
  get_vertical_order(root->right, h_dis+1, mp);
}

int main(){
  node*root = new node(10);
  root->left = new node(7);
  root->right = new node(4);
  root->left->left = new node(3);
  root->left->right = new node(11);
  root->right->left = new node(14);
  root->right->right = new node(6);

  map<int,vi> mp;
  int h_dis = 0;
  get_vertical_order(root, h_dis, mp);
  map<int,vi>::iterator it;
  for(it=mp.begin(); it!=mp.end(); it++, cout<<endl)
    for(int i=0; i<(it->ss).size(); i++)
      cout<<(it->ss)[i]<<" ";
    
  return 0;
}