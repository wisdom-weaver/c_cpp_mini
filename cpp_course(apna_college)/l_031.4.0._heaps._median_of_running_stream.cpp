#include <bits/stdc++.h>
using namespace std;

priority_queue<int, vector<int>>pqmax;
priority_queue<int, vector<int>, greater<int>>pqmin;

void insert(int x){
  if(pqmin.size()==pqmax.size()){
    if(pqmax.size()==0){ pqmax.push(x); return; }

    if(x<pqmax.top()) pqmax.push(x);
    else pqmin.push(x);
  }else{
    if(pqmax.size()>pqmin.size()){
      if(x>=pqmax.top())  pqmin.push(x);
      else{
        int temp = pqmax.top(); pqmax.pop();
        pqmin.push(temp);
        pqmax.push(x);
      }
    }else{
      if(x<=pqmin.top())  pqmax.push(x);
      else{
        int temp = pqmin.top(); pqmin.pop();
        pqmax.push(temp);
        pqmin.push(x);
      }
    }
  }
}

double find_median(){
  if(pqmax.size()==pqmin.size())
    return (pqmin.top()+pqmax.top())/2.0;
  if(pqmax.size()>pqmin.size())
    return pqmax.top();
  else 
    return pqmin.top();
}

int main(){
  vector<int> a ={10,15,21,30,18,19};
  for(int i=0; i<a.size(); i++){
    insert(a[i]);
    cout<<"at i:"<<i<<"="<<find_median()<<endl;
  }

  return 0;
}