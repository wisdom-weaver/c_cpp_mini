#include <bits/stdc++.h>
using namespace std;

int water_trapped(vector<int> a)
{
  int n = a.size(), ans = 0, i = 0;
  stack<int>st;
  a.push_back(0);
  while(i<n){
    while(!st.empty() && a[st.top()]<a[i]){
      int cur = st.top();
      st.pop();
      if(st.empty()) break;
      int diff = i-st.top()-1;
      ans += (min(a[st.top()], a[i]) - a[cur]) * diff;
    }
    st.push(i);
    i++;
  }
  return ans;
}

int main()
{
  vector<int> a = {0,1,0,2,1,0,1,3,2,1,2,1};
  cout << water_trapped(a);
  return 0;
}
