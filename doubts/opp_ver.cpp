
#include <bits/stdc++.h>
using namespace std;
 
class Integer {
private: int i;
public:
    Integer(int i = 0){this->i = i;}

    Integer operator #(){
        // cout<<"int arg a:"<<a<<endl;
        // cout<<"int arg b:"<<b<<endl;
        Integer temp;
        temp.i = i+1;
        return temp;
    }
    void display(){
        cout << "i = " << i << endl;
    }
};
 
int main()
{
    Integer i1(3);
    cout << "Before increment: ";
    i1.display();
    Integer i2 = i1#3;
    cout << "After post increment: ";
    i2.display();
}