#include <iostream>
using namespace std;

int main()
{
    cout << "Enter character: ";
    char ch;
    cin >> ch;
    if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z'))
        cout << ch << " is alphabet" << endl;
    else if (ch >= '0' && ch <= '9')
        cout << ch << " is a digit" << endl;
    else
        cout << ch << " is special character" << endl;

    return 0;
}