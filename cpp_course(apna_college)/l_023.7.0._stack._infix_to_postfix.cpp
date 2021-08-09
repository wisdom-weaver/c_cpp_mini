#include <iostream>
#include <stack>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;

int prec(char c){
  if(c=='^') return 3;
  else if(c=='*' || c=='/') return 2;
  else if(c=='+' || c=='-') return 1;
  else if(c==')' || c=='(') return 0;
  else return -1;
}

string infix_to_postfix(string s)
{
  stack<char> st;
  string res;
  for(int i=0;i<s.length();i++){
    if(prec(s[i])==-1)
      res+=s[i];
    else if(s[i]=='(')
      st.push(s[i]);
    else if(s[i]==')'){
      while(!st.empty() && st.top()!='('){
        res += st.top();
        st.pop();
      }
      cout<<st.empty();
      if(!st.empty() && st.top()=='(') st.pop(); // pop prev opening bracket
    }else{
      while(!st.empty() && prec(st.top()) > prec(s[i])){
        res+=st.top();
        st.pop();
      }
      st.push(s[i]);
    }
  }
  while(!st.empty()){
    res+=st.top();
    st.pop();
  }
  return res;
}

string infix_to_prefix(string s){
  string out = s;
  reverse(out.begin(), out.end());
  
  for(int i=0;i<out.length();i++)
    if(out[i]=='(') out[i]=')';
    else if(out[i]==')') out[i]='(';

  out = infix_to_postfix(out);
  reverse(out.begin(), out.end());
  return out;
}

int main()
{
  string infix = "(a-b/c)*(a/k-l)";
  cout << "infix  : " << infix << endl;
  string postfix = infix_to_postfix(infix);
  cout << "postfix: " << postfix << endl;
  string prefix = infix_to_prefix(infix);
  cout << "prefix: " << prefix << endl;
  return 0;
}
