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
    // copy constructor
    Student (Student &st){
      this->name = st.name;
      this->id = st.id;
      this->_class = st._class;
    }
    void display(){ 
      cout<<"\nStudent: "<<name<<"("<<id<<")"<<"=> "<<_class; 
    }
};

int main(){
  Student danish("Danish", 97200069, "BCA-2A");
  danish.display();
  Student danish_copy(danish);
  danish_copy.display();
  return 0;
}

/*
Output:

Student: Danish(97200069)=> BCA-2A
Student: Danish(97200069)=> BCA-2A
*/