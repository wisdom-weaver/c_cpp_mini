#include <iostream>
using namespace std;

class Account{
  private: 
    string type;
    float rate;
    int time_y;
  public:
    Account(){
      cout<<"Enter Account Type:"; getline(cin, type);
      cout<<"Enter Account Time in years: "; cin>>time_y;
      update_rate();
    }
    void update_rate(){
      float rate = 0;
      if (type=="current") rate = 4.0;
      else if(type=="savings") rate = 6.0;

      if(time_y>5) rate += 3.0; 
      this->rate = rate;
    }
    void display_acc_details(){
      cout<<"Account of type: "<<type<<"for time "<<time_y<<endl;
      cout<<"your intrest rate: "<<rate<<"\n----\n";
    }
    
};

int main(){
  Account ac1; ac1.display_acc_details(); cin.ignore();
  Account ac2; ac2.display_acc_details(); cin.ignore();
  Account ac3; ac3.display_acc_details(); cin.ignore();
  return 0;
}

/*output:
Enter Account Type:current
Enter Account Time in years: 3
Account of type: currentfor time 3
your intrest rate: 4
----
Enter Account Type:savings
Enter Account Time in years: 2
Account of type: savingsfor time 2
your intrest rate: 6
----
Enter Account Type:savings
Enter Account Time in years: 7
Account of type: savingsfor time 7
your intrest rate: 9
----

*/