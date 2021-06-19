#include <iostream>
#include <utility>
#include <string>
#include <stack>
#define ln printf("\n")
using namespace std;

pair<int,int> pos_to_num(string pos_s){
  pair <int, int> pos;
  pos.first = (int)(pos_s[0]-'a');
  pos.second = (int)(pos_s[1]-'0');
  return pos;
}

string pos_to_s(pair<int,int> pos){
  string pos_s = "";
  pos_s += (char)(pos.first+'a');
  pos_s += (char)(pos.second+'0');
  return pos_s;
}

void print_pair(pair<int,int> p){
  cout<<p.first<<":"<<p.second;
}

void print_stack(stack<string> st){ 
  stack <string> temp = st;
  if(temp.empty()){ cout<<"EMPTY"<<endl; return; }
  while(!temp.empty()){ cout<<temp.top()<<" <- "; temp.pop(); } cout<<"TOP";
  ln;
}

int is_on_board_p(pair<int,int> p){
  return (p.first>=0 && p.first<8 && p.second>=1 && p.second<=8);
}

int is_on_board_s(string pos){
  return (pos[0]>='a' && pos[0]<='h' && pos[1]>='0' && pos[1]<='8');
}

pair<int, int> move(pair<int,int>p, int move_x, int move_y){
  p.first += move_x;
  p.second += move_y;
  return p;
}

pair<int, int> move_to(pair<int,int>p, int move_idx){
  switch(move_idx){
    case 0: return move(p, +2, +1);
    case 1: return move(p, +1, +2);
    case 2: return move(p, -1, +2);
    case 3: return move(p, -2, +1);
    case 4: return move(p, -2, -1);
    case 5: return move(p, -1, -2);
    case 6: return move(p, +1, -2);
    case 7: return move(p, +2, -1);
    default: return p;
  }
}

int knight_r( pair<int,int> curr,  pair<int,int> final, stack<string> *st){
  cout<<" "<<pos_to_s(curr)<<endl;
  if(curr.first==final.first && curr.second==final.second){ cout<<"\nFOUND\n"; return 1;}
  st->push(pos_to_s(curr));
  int i=0;
  while(i<8){ 
    if(!is_on_board_p(move_to(curr, i))) continue;
    return knight_r(move_to(curr, i), final, st);
  }
  return 0;
}

int knight(string start, string finish) {
  ln;
  pair<int, int> s = pos_to_num(start);
  cout<<"start  "<<start<<" ";   print_pair(s); cout<<" "<<pos_to_s(s); ln;
  // cout<<is_on_board_s(start)<<is_on_board_p(s); ln;
  pair<int, int> f = pos_to_num(finish);
  cout<<"finish "<<finish<<" ";  print_pair(f); cout<<" "<<pos_to_s(f); ln;
  // cout<<is_on_board_s(finish)<<is_on_board_p(f); ln;
  ln;
  stack<string> st;
  cout<<"knight_r: "<<knight_r(s, f, &st)<<endl;
  cout<<"st("<<st.size()<<")=> "; print_stack(st);
  return st.size();
}

int main(){ 
  string start = "a1", final = "c1";
  int path = knight(start, final);
  cout<<"knight(\""<<start<<"\", \""<<final<<"\") => "<<path<<endl;
  int i=30; while(i--) cout<<"-";
  ln; ln;
}