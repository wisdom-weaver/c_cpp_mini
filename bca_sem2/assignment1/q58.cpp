#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    cout << "Enter marks in all subjects:  ";
    int n=5, tot=0;
    
    int marks[n];
    for(int i=0;i<n;i++){
        cin>>marks[i];
        tot += marks[i];
    }
    
    cout << "Enter maximum obtainable marks:  ";
    int max_tot; cin>>max_tot; 
    
    float percent = (tot*100.0)/max_tot;
    cout << "Total: "<<tot<<endl;
    cout<<"percent: "<<percent<<endl;

    cout<<"Grade: ";
    if(percent>=90) cout<<"A";
    else if(percent>=80) cout<<"B";
    else if(percent>=70) cout<<"C";
    else if(percent>=60) cout<<"D";
    else if(percent>=40) cout<<"E";
    else cout<<"F";
    cout<<endl;

    end: return 0;
}