#include <iostream>
using namespace std;

int main()
{
    cout << "Enter character: ";
    char ch;
    cin >> ch;
    if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z'))
        cout << ch << " is a character" << endl;
    else
        cout << ch << " is not a character" << endl;
    return 0;
}