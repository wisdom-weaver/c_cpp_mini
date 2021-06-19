#include <iostream>
using namespace std;

int main()
{
    cout << "Enter character: ";
    char ch;
    cin >> ch;
    if (ch >= 'A' && ch <= 'Z')
        cout << ch << " is uppercase" << endl;
    else if (ch >= 'a' && ch <= 'z')
        cout << ch << " is lowercase" << endl;
    else
        cout << ch << " is not an alphabet" << endl;

    return 0;
}