#include <iostream>
using namespace std;

int main()
{
    cout << "Enter amount: ";
    int n;
    cin >> n;
    int notes[] = {2000, 500, 200, 100, 50, 20, 10, 5, 2, 1};
    int tot = 0;
    for (auto note : notes)
    {
        if (n > note)
        {
            int x = n / note;
            cout << x << " notes of " << note << endl;
            n %= note;
            tot += x;
        }
    }
    return 0;
}