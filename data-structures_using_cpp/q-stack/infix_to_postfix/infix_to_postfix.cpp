#include <iostream>
#include <stack>
using namespace std;

int prec(char op){
  if(op=='^') return 3;
  if(op=='*'||op=='/'||op=='%') return 2;
  if(op=='+'||op=='-') return 1;
  return -1;
}

bool is_operator(char op){
  string ops = "()+-*%^/";
  int pos = ops.find(op);
  return pos>=0 && pos<ops.length();
}

string get_postfix_from_infix(string inf){
  string post="";
  stack<char> st;

  for(int i=0; i<inf.length(); i++){
    char ch = inf[i];
    if(!is_operator(ch)){ post+=ch; continue; }

    if(ch=='('){
      st.push(ch);
    }else if(ch==')'){ 
      while(!st.empty() && st.top()!='('){ post+=st.top(); st.pop(); }
      if(!st.empty()) st.pop();
    }else{
      while( !st.empty() && prec(st.top()) > prec(ch) ){
        post+=st.top(); st.pop();
      }
      st.push(ch);
    }
  }
  while(!st.empty()){ post+=st.top(); st.pop(); }
  return post;
}

int main(){
  string infix_exp = "(a-b/c)*(a/k-l)";
  // string infix_exp = "a+b";
  cout<<"infix_exp: "<<infix_exp<<endl;
  cout<<"postfix_exp: "<<get_postfix_from_infix(infix_exp)<<endl;
}