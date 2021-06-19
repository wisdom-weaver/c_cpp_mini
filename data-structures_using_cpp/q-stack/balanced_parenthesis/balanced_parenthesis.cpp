#include <iostream>
#include <stack>
using namespace std;

bool check_balanced_parenthesis(string s){
  stack<char> st;
  int n =s.length();
  for(int i=0;i<n;i++){
    char ch = s[i];
    if(ch=='{'||ch=='['||ch=='(')
      st.push(ch);
    else if(ch=='}') 
      if(st.top()=='{') st.pop(); 
      else return false;
    else if(ch==']') 
      if(st.top()=='[') st.pop(); 
      else return false;
    else if(ch==')') 
      if(st.top()=='(') st.pop(); 
      else return false;
  }
  return st.empty();
}

int main(){
  string s = "{[(a+b)]}";
  cout<<"string: "<<s<<endl;
  cout<<"string is "<<(check_balanced_parenthesis(s)?"is":"is not")<<" balanced"<<endl;
  s = "({a}";
  cout<<"string: "<<s<<endl;
  cout<<"string is "<<(check_balanced_parenthesis(s)?"is":"is not")<<" balanced"<<endl;
  return 0;
}