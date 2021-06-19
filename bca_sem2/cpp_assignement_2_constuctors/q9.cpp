#include <iostream>
using namespace std;

class Transaction{
private:
  string tx_id;
  string acc_name;
  float tx_amt;

public:
  Transaction()
  {
    this->tx_id = "UNKNOWN";
    this->tx_amt = -1;
    this->acc_name = "UNKONWN";
  }
  void dynamic_initilization(){
    cout<<"\nEnter transaction id: "; getline(cin, tx_id);
    cout<<"Enter Account Holder Name: "; getline(cin, acc_name);
    cout<<"Enter Transaction Amount: "; cin>>tx_amt;
  }
  void display_tx_details()
  {
    cout << "\ntx_id: " << tx_id << endl;
    cout << "Accout Name: " << acc_name << endl;
    cout << "Rs. " << tx_amt<<endl;
  }
};

int main(){
  Transaction tx;
  tx.display_tx_details();
  tx.dynamic_initilization();
  tx.display_tx_details();
  return 0;
}

/*output:

tx_id: UNKNOWN
Accout Name: UNKONWN
Rs. -1

Enter transaction id: TX0909
Enter Account Holder Name: Danish Ansari
Enter Transaction Amount: 40000

TX0909 
Accout Name: Danish Ansari
Rs. 40000

*/