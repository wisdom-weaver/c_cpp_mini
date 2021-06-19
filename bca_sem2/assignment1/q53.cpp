#include <iostream>
using namespace std;

int main()
{
    cout << "Enter angles of triangle: ";
    int a, b, c;
    cin >> a >> b >> c;
    if (a + b + c == 180)
        cout << "triangle is valid" << endl;
    else
        cout << "triangle is not valid" << endl;
    return 0;
}