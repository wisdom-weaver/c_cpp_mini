#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    cout << "Enter units: ";
    int units; cin>>units;
    float cost=0;
    
    units = max(units, 0);
    cost += min(units, 50)*0.50;

    units = max(units-50, 0);
    cost += min(units, 100)*0.75;
    
    units = max(units-100, 0);
    cost += min(units, 100)*1.20;
    
    units = max(units-100, 0);
    cost += units*1.50;

    cout<<"cost: Rs "<<cost<<endl;
    end: return 0;
}