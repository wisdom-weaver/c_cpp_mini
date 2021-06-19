#include <iostream>
using namespace std;

class Student{
  private:
    string name;
    int id=0;
    string _class;
    
  public:
    // default constructor 
    Student (){
      this->name = "Def Stu";
      this->id = 999999;
      this->_class = "BCA-2A";
    }
    // constructor 1
    Student (string name, int id, string _class){
      this->name = name;
      this->id = id;
      this->_class = _class;
    }
    // constructor 2
    Student (string name){
      this->name = name;
    }
    void display(){ 
      cout<<"\nStudent: "<<name<<"("<<id<<")"<<"=> "<<_class; 
    }
};

int main(){
  // default constructor 
  Student st1; st1.display();
  // constructor 1
  Student st2("Danish", 97200069, "BCA-2A"); st2.display();
  // constructor 2
  Student st3("Kunal"); st3.display();
  return 0;
}

/*
Output:

Student: Def Stu(999999)=> BCA-2A
Student: Danish(97200069)=> BCA-2A
Student: Kunal(0)=> 
*/