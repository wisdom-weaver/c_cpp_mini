#include <iostream>
using namespace std;

class Complex{
  private: 
    int re, im;
  public:
    Complex(){ re = im = 0;}
    Complex(int a){ re = im = a; }
    Complex(int x, int y): re(x), im(y) {};
    friend Complex CalcSum(Complex A, Complex B);
    void display(){
      cout<<" re="<<re<<", im:"<<im<<endl;
    }
};

Complex CalcSum(Complex A, Complex B){
  int re = A.re+B.re;
  int im = A.im+B.im;
  return Complex(re, im);
}

int main(){
  Complex A(3);
  Complex B(2,3);
  Complex sum;
  sum = CalcSum(A,B);
  cout<<"sum: "; sum.display();
  return 0;
}

/*output:

*/