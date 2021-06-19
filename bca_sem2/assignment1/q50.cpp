#include <iostream>
using namespace std;

int main()
{
    cout << "Enter week day no: ";
    int d;
    cin >> d;
    if (d == 1)
        cout << "Sunday";
    else if (d == 2)
        cout << "Monday";
    else if (d == 3)
        cout << "Tuesday";
    else if (d == 4)
        cout << "Webnesday";
    else if (d == 5)
        cout << "Thusday";
    else if (d == 6)
        cout << "Friday";
    else if (d == 7)
        cout << "Saturday";
    else
        cout << "Invalid day no";
    cout << endl;
    return 0;
}