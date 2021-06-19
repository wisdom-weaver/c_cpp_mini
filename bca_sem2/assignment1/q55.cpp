#include <iostream>
using namespace std;

int main()
{
    cout << "Enter sides of triangle: ";
    int a, b, c;
    cin >> a >> b >> c;
    if (a == b && b == c)
        cout << "triangle is equilaterial" << endl;
    else if (a == b || b == c || c == a)
        cout << "triangle is isoceles" << endl;
    else
        cout << "traingle is scalar" << endl;
    return 0;
}