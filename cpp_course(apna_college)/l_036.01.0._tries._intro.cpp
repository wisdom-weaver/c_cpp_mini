#include <bits/stdc++.h>
using namespace std;

class Trie{
public:
  class node{
  public:
    bool end;
    node* next[26];
    node(){
      end=false;
      for(int i=0;i<26;i++) next[i]=NULL;
    }
  };
  
  node* trie;
  Trie(){
    trie = new node();
  }
  
  void insert(string word){
    int i=0;
    node* it=trie;
    while(i<word.size()){
      int c = word[i]-'a';
      if(it->next[c]==NULL)
        it->next[c] = new node();
      it = it->next[c];
      i++;
    }
    it->end=true;
  }

  bool search(string word){
    int i=0;
    node*it = trie;
    while(i<word.size()){
      int c = word[i]-'a';
      if(it->next[c]==NULL) 
        return false;
      it = it->next[c];
      i++;
    }
    return it->end;
  }
};

int main(){
  Trie myTrie;
  vector<string> words={"anjora","danish"};
  for(auto w: words)
    myTrie.insert(w); 
  cout<<myTrie.search("anjora")<<endl;
  cout<<myTrie.search("dan")<<endl;
  cout<<myTrie.search("danish")<<endl;

}