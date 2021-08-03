#include <iostream>
using namespace std;

class student
{
public:
  string name;
  int age;
  bool gender;
  void print_info()
  {
    cout << name << ", " << age << ", " << gender << "\n--\n";
  }
  
  // operator overloading
  bool operator==(student &a)
  {
    return (name == a.name && age == a.age && gender == a.gender);
  }
};

int main()
{
  student a;
  a.name = "Danish";
  a.age = 20;
  a.gender = 0;

  // student arr[3];
  // for (int i = 0; i < 3; i++)
  // {
  //   cout << "name :";
  //   cin >> arr[i].name;
  //   cout << "age :";
  //   cin >> arr[i].age;
  //   cout << "gender :";
  //   cin >> arr[i].gender;
  //   arr[i].print_info();
  // }

  student b;
  b.name = "Danish";
  b.age = 20;
  b.gender = 0;

  a.print_info();
  b.print_info();

  if (a == b)
    cout << "student a and b are same";
  else
    cout << "student a and b are not same";

  return 0;
}

// compexity O(n)