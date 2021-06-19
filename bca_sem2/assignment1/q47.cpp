#include <iostream>
using namespace std;

int main()
{
    cout << "Enter character: ";
    char ch;
    cin >> ch;
    if (!((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z')))
        cout << "Invalid character" << endl;
    else
    {
        if (ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U' || ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
            cout << ch << " is a vowel" << endl;
        else
            cout << ch << " is not a consonant" << endl;
    }
    return 0;
}