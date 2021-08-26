#include <bits/stdc++.h>
using namespace std;

int main(){
  int ar[] = {2000,500,200,100,50,20,10,5,2,1};
  int c=0, amt = 350;
  int n = sizeof(ar)/sizeof(ar[0]);
  for(int i=0;i<n;i++){
    int count = amt/ar[i];
    if(count==0) continue;
    cout<<count<<"x "<<ar[i]<<endl;
    amt = amt%ar[i];
    c+=count;
  }
  cout<<"no of notes/coins:"<<c<<endl;
  return 0;
}