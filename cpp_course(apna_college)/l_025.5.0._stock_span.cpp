#include <bits/stdc++.h>
using namespace std;

// stock span is no of days price was lower than today
vector<int> stock_span(vector<int> prices){
  vector<int> ans;
  stack<pair<int,int>> st;
  for(auto price: prices){
    int days = 1;
    while(!st.empty() && st.top().first <= price){
      days += st.top().second;
      st.pop();
    }
    st.push({price,days});
    ans.push_back(days);
  }
  return ans;
}

int main()
{
  vector<int> a = {100, 80, 60, 70, 60, 75, 85};
  vector<int> res = stock_span(a);
  for(auto i: a)
    cout<<i<<" ";
  cout<<endl;
  for(auto i: res)
    cout<<i<<" ";
  cout<<endl;
  return 0;
}
