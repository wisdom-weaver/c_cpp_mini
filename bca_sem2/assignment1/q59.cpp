#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    cout << "Enter basic salary: ";
    float bs; cin>>bs;
    float gs;

    if(bs<=0){ cout<<"invalid salary"; goto end; }
    if(bs<=10000.0)
        gs = bs*(1+0.2+0.8);
    else if(bs<=20000.0)
        gs = bs*(1+0.25+0.90);
    else if(bs>20000.0)
        gs = bs*(1+0.30+0.8); 

    cout<<"Gross Salary: Rs "<<gs<<endl;
    end: return 0;
}