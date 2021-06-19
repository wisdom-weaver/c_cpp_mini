#include <iostream>
using namespace std;

int main()
{
    cout << "Enter year: ";
    int y;
    cin >> y;
    if ((y % 400 == 0) || (y % 100 != 0 && y % 4 == 0))
        cout << y << " is a leap year" << endl;
    else
        cout << y << " is not a leap year" << endl;
    return 0;
}