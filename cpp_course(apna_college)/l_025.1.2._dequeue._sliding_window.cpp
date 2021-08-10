#include <iostream>
#include <deque>
#include <vector>
using namespace std;

int main()
{
  int k = 3;
  int n = 8;
  int arr[n] = {1, 3, -1, -3, 5, 3, 6, 7};
  vector<int> a(n);
  for (int i = 0; i < n; i++)
    a[i] = arr[i];

  deque<int> dq;
  vector<int> ans;

  // get first max in 1st window
  for (int i = 0; i < k; i++){
    while (!dq.empty() && a[dq.back()] < a[i])
      dq.pop_back(); // remove everything fron back till its the dq_el is lesser than curr_elem
    dq.push_back(i); // push the curr_el at back
  }
  ans.push_back(a[dq.front()]);

  // keep doing the same for the rest of the windows
  for (int i = k; i < n; i++){
    if(dq.front() <= i-k) // if the front_el idx was out of window remove it
      dq.pop_front();
    while (!dq.empty() && a[dq.back()] < a[i])
      dq.pop_back(); // remove everything fron back till its the dq_el is lesser than curr_elem
    dq.push_back(i); // push the curr_el at back
    ans.push_back(a[dq.front()]);
  }

  cout<<"ar : ";
  for (int i = 0; i < a.size(); i++) cout<<a[i]<<" ";
    cout<<endl;
  cout<<"ans: ";
  for (int i = 0; i < ans.size(); i++) cout<<ans[i]<<" ";
    cout<<endl;
  cout<<"END\n";
  return 0;
}
