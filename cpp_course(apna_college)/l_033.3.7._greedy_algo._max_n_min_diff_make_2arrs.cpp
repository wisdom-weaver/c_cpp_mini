#include <bits/stdc++.h>
using namespace std;


int main(){
  vector<int> a = {12, -3, 10, 0};
  int n = a.size();

  sort(a.begin(), a.end());
  long long mn=0, mx=0;
  for(int i=0;i<n/2;i++){
    mx += (a[i+n/2] - a[i]);
    mn += (a[2*i+1] - a[2*i]);
  }

  cout<<"max diff: "<<mx<<endl;
  cout<<"min diff: "<<mn<<endl;
  return 0;
}