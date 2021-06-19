#include <iostream>
using namespace std;
class real{  
  public:
    string name;
    double bill;
    int age;
    int distance;
    int rem;
    double calc_bill(double distance){
        if(distance>=0 && distance<=100){
            bill=distance*1.0;
            return bill;
        }else if(distance>100 && distance<=500){
         rem=distance-100;
            bill=(100*1.0)+(rem*1.5);
            return bill;
        }else{
            rem=distance-500;
            bill=(100*1.0)+(400*1.5)+rem*2.0;
            return bill;
        }
    }
};
int main(){
	real obj;	
  cout<<"bill is "<<obj.calc_bill(100.0)<<endl;
	return 0;
}