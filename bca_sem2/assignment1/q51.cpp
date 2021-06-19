#include <iostream>
using namespace std;

int main()
{
    cout << "Enter month no: ";
    int m;
    cin >> m;
    if(m==1) cout<<"January => 31days";
    else if(m==2) cout<<"February => 28/29days";
    else if(m==3) cout<<"March => 31days";
    else if(m==4) cout<<"April => 30days";
    else if(m==5) cout<<"May => 31days";
    else if(m==6) cout<<"June => 30days";
    else if(m==7) cout<<"July => 31days";
    else if(m==8) cout<<"August => 31days";
    else if(m==9) cout<<"September => 30days";
    else if(m==10) cout<<"October => 31days";
    else if(m==11) cout<<"November => 30days";
    else if(m==12) cout<<"December => 31days";
    else cout << "Invalid day no";
    cout << endl;
    return 0;
}