#include <iostream>
using namespace std;

class Employee{
private:
  string name;
  string department;
  int id;

public:
  // default
  Employee(){
    name = "UNKNOWN";
    department = "UNKNOWN";
    id = 0;
  }
  // parametrized
  Employee(string name, string department, int id){
    this->name = name;
    this->department = department;
    this->id = id;
  }
  // copy
  Employee(Employee &emp){
    name = emp.name;
    department = emp.department;
    id = emp.id;
  }
  
  void display_emp_details(){
    cout << "\n=> Emp id: " << id<<endl;
    cout << name<< " ( "<<department<<" )"<<endl;
  }
};

int main(){
  Employee e0; 
  e0.display_emp_details();
  Employee e1("Mr. John Walter", "Marketing", 01); 
  e1.display_emp_details();
  Employee e2(e1); 
  e2.display_emp_details();
  
  return 0;
}

/*output:


=> Emp id: 0
UNKNOWN ( UNKNOWN )

=> Emp id: 1
Mr. John Walter ( Marketing )

=> Emp id: 1
Mr. John Walter ( Marketing )


*/