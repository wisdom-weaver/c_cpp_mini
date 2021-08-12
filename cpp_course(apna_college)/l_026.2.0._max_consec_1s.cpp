#include <bits/stdc++.h>
using namespace std;

// you can change k no of 0's to 1's 
// and find out the maximum no of consec 1's
int max_consec_1s(vector<int> a, int k){
  // our problem is reduced max number(atmost k) of zeros we can fit in a window
  int n = a.size();
  int z_count=0, i=0, ans=0;
  for(int j=0; j<a.size(); j++){ 
    if(a[j]==0) z_count++; // add 0's for incresing window size
    while(z_count > k){
      if(a[i]==0) z_count--; // remove added 0's
      i++; // decrease window size
    }
    ans = max(ans, j-i+1); // j-i+1 is the window size
  }
  return ans;
}

int main(){
  vector<int> a = {0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1};
  int k = 3;
  cout << "3 sum: " << max_consec_1s(a,k) << endl;
  return 0;
}