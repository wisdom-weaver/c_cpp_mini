#include <bits/stdc++.h>
using namespace std;

// using 2 pointers 
bool exists_3_sum(vector<int> a, int target){
  int n = a.size();
  sort(a.begin(),a.end());
  for(int i=0;i<n;i++){
    int lo = i+1, hi = n-1;
    while(lo<hi){
      int curr = a[i] + a[lo] + a[hi];
      if(curr == target) return true;
      else if(curr < target) lo++;
      else if(curr > target) hi--;
    }
  }
  return false;
}

int main(){
  vector<int> a = {1,3,6,7,9,12};
  int target = 24;
  cout << "3 sum: " << exists_3_sum(a,target) << endl;
  return 0;
}

// time complexity O(n^2)