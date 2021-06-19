//PRAKHAR CHAKRAVARTY---(20BCE10271)---SLOT-A11+A12+A13
//FACULTY--VIKASH


//Real Life Problem Tackling Program.

//IDEA:-TO Prepare a railway ticket
//charging the bill as:- 1Rs/km till 100km
//Above 100km,till 500km charge 1.5Rs/km.
//Above 500km charge 2Rs/km
//If  the person is senior citizen or a child below 10 yrs then 50 percent discount is provided on the bill.
//Also allot Lower berth to senior citizen. To other ,any random berth can be alloted.


#include<cstdlib>
#include <iostream>
#include <stdio.h>
using namespace std;

#define dash(N) {int n=N; while(n--) printf("-");}

class real{  
  public:
    string name;
    double bill;
    int age;
    double distance;
    int rem;
    double calc_bill(double distance){//For calculating the initial bill without any discount
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
    double discount(int age,double b){//For senior citizen and child discount.
        double nb=b;
        if(age>=60||age<=10){
           b=b-(b*0.5);
        return b;
        }else{return nb;}
    }string stats(int a2){//For segregating child,tennager,adult andnsenior citizen.
        string stat="";
        if(a2>=60){stat="senior citizen";return stat;}
        else if(a2<=10){stat="child";return stat;}
        else if(a2>10&&a2<=17){stat="teenager";return stat;}
        else{stat="adult";return stat;}
    }
    string berth(string str){//Providing lower berth to senior citizen and random to others.
        string str2="";
        if(str=="senior citizen"){
            str2="Lower berth";return str2;
        }else{int ran=rand();
        if(ran%2==0){str2="Lower berth";return str2;}
        else if(ran%3==0){str2="Upper berth";return str2;}
        else{str2="Middle berth";return str2;}
        }
    }
};
int main(){//for taking input and displaying the ticket.
	real obj;
    double d = 300.5;
    string s;
    s = "Danish Ansari";
    string status;
    status ="reserved";
    string birth ;
    birth = "lower";
    int a = 18;
    string gen = "male";
    double ini_bill = 100.00;
    double dis_bill = 90.00;

    cout<<"enter the distance :"<<endl;
    cin>>d;	
    ini_bill=obj.calc_bill(d);
    cout<<"enter the age :"<<endl;
    cin>>a;
    dis_bill=obj.discount(a,ini_bill);
    cin.ignore();
    cout<<"enter your name :";
    getline(cin, s);
    cout<<"enter your gender :";
    getline(cin, gen);
    status=obj.stats(a);
    birth=obj.berth(status);
    int seat=rand()%50+1;

  cout<<endl; dash(55);
  cout<<"Railway Ticket";
  dash(55); cout<<endl;

  printf("%20s | ", "Name");
  printf("%5s | ", "Age");
  printf("%15s | ", "Bill");
  printf("%15s | ", "Discounted_Bill");
  printf("%10s | ", "Gender");
  printf("%15s | ", "Status");
  printf("%8s | ", "Seat");
  printf("%15s | ", "Berth");
  cout<<endl;
  printf("%20s | ", s.c_str());
  printf("%5d | ", a);
  printf("%15.2f | ", ini_bill);
  printf("%15.2f | ", dis_bill);
  printf("%10s | ", gen.c_str());
  printf("%15s | ", status.c_str());
  printf("%8d | ", seat);
  printf("%15s | ", birth.c_str());
  
  cout<<endl; dash(55);
  cout<<"Happy Journey";
  dash(55); cout<<endl<<endl;
	return 0; 
}