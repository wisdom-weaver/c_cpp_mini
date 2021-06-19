#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    cout << "Enter cost price: Rs ";
    float cp; cin>>cp;
    cout << "Enter selling price: Rs "; 
    float sp; cin>>sp;
    if(sp==cp)
        cout<<"No profit / loss"<<endl;
    else if(sp>cp)
        cout<<"profit: "<<(sp-cp)<<endl;
    else if(sp<cp)
        cout<<"loss: "<<(cp-sp)<<endl;

    end: return 0;
}