#include <iostream>
using namespace std;

class Transaction{
private:
  string tx_id;
  string acc_name;
  float tx_amt;

public:
  Transaction(string tx_id, string acc_name, float tx_amt)
  {
    this->tx_id = tx_id;
    this->tx_amt = tx_amt;
    this->acc_name = acc_name;
  }
  void display_tx_details()
  {
    cout << "\ntx_id: " << tx_id << endl;
    cout << "Accout Name: " << acc_name << endl;
    cout << "Rs. " << tx_amt;
  }
};

int main(){
  Transaction tx("AAV92320", "MR. Rich", 40000);
  tx.display_tx_details();
  return 0;
}

/*output:
tx_id: AAV92320
Accout Name: MR. Rich
Rs. 40000
*/