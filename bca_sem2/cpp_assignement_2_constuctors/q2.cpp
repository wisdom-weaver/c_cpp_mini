#include <iostream>
using namespace std;

class Student{
  private:
    string name;
    int id;
    string _class;
    
  public:
    Student (string name, int id, string _class){
      this->name = name;
      this->id = id;
      this->_class = _class;
    }
    void display(){ 
      cout<<"\nStudent: "<<name<<"("<<id<<")"<<"=> "<<_class; 
    }
};

int main(){
  Student danish("Danish", 97200069, "BCA-2A");
  danish.display();
  return 0;
}

/*
Output:
Student: Danish(97200069)=> BCA-2A
*/