#include <iostream>
using namespace std;

class Transaction{
private:
  string tx_id;
  string acc_name;
  float tx_amt;

public:
  //use of default constructor to denote unknown and empty vars
  Transaction()
  {
    this->tx_id = "UNKNOWN";
    this->tx_amt = -1;
    this->acc_name = "UNKONWN";
  }
  void display_tx_details()
  {
    cout << "\ntx_id: " << tx_id << endl;
    cout << "Accout Name: " << acc_name << endl;
    cout << "Rs. " << tx_amt;
  }
};

int main(){
  Transaction tx;
  tx.display_tx_details();
  return 0;
}

/*output:
tx_id: UNKNOWN
Accout Name: UNKONWN
Rs. -1
*/