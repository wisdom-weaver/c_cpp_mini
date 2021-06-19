#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    cout << "Enter a b c in expression \n=> ax^2 + bx + c = 0 : ";
    int a, b, c;
    cin >> a >> b >> c;
    int d = b*b - 4*a*c;
    if (d==0){
        float r1 = -b/(2.0*a);
        cout<<"single root: "<<r1<<endl;
    }else if(d>0){
        float r1 = (-b + sqrt(d)) / (2.0*a);
        float r2 = (-b - sqrt(d)) / (2.0*a);
        cout<<"real and distinct roots: "<<r1<<" , "<<r2<<endl;
    }else{
        float r1 = (-b) / (2.0*a);
        float r2 = (sqrt(-d)) / (2.0*a);
        cout<<"complex roots: "<<endl;
        cout<<r1<<" + "<<r2<<"i"<<endl;
        cout<<r1<<" - "<<r2<<"i"<<endl;
    }
    return 0;
}