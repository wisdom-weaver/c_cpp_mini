#include <iostream>
using namespace std;

#define swap(a,b) {int t=a; a=b; b=t;}

int main()
{
    cout << "Enter sides of triangle: ";
    int a, b, c;
    cin >> a >> b >> c;
    if(a>b) swap(a,b);
    if(b>c) swap(b,c);
    if((a+b)>c)
        cout<<"triangle is valid"<<endl;
    else 
        cout<<"triangle is not valid"<<endl;
    return 0;
}