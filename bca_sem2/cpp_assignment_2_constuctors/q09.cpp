#include <iostream>
#include <string.h>
using namespace std;

class String{
    int length;
    char *name;
  public:
    String(char* ch){
      length = strlen(ch);
      name = new char[length];
      name = ch;
    }
    void join(char* b){
      length += strlen(b);
      char *a = name;
      name = new char[length];
      strcpy(name, a);
      strcat(name, b);
    }
    void get_length(){
      cout<<"length: "<<length<<endl;
    }
    void display(){
      cout<<name<<endl;
    }
};

int main(){
  String name("Danish");
  name.display();
  name.get_length();

  name.join(" Ansari");
  name.display();
  name.get_length();
}