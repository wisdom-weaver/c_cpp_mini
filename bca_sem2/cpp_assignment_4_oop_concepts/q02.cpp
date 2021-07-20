#include <iostream>
using namespace std;

class Student
{
protected:
  int roll;
  string name;
  string course;

public:
  void input_student()
  {
    cout << "Enter roll no: ";
    cin >> roll;
    cout << "Enter name: ";
    cin.ignore();
    getline(cin, name);
    cout << "Enter course: ";
    getline(cin, course);
  }
  void display_student()
  {
    cout << "=> \nStudent details: " << name << " ( " << roll << " )\n";
    cout << "enrolled in course " << course << "\n";
  }
};

class Exam : private Student
{
  int mark1, mark2, mark3;

public:
  void input_marks()
  {
    Student::input_student();
    cout << "Enter marks: ";
    cin >> mark1 >> mark2 >> mark3;
  }
  void display_marks()
  {
    Student::display_student();
    cout << "marks: " << mark1 << ", " << mark2 << ", " << mark3 << endl;
  }
};

int main()
{
  int n = 5;
  Exam exs[n];
  int i = 1;
  for (int i = 0; i < n; i++)
  {
    cout << "For student " << i << endl;
    exs[i].input_marks();
    cout << "\n---------\n";
  }
  for (int i = 0; i < n; i++)
  {
    cout << "Detials of student " << endl;
    exs[i].display_marks();
    cout << "\n---------\n";
  }
  return 0;
}

/*

For student 0
Enter roll no: 1
Enter name: Danish Ansari
Enter course: BCA
Enter marks: 20 20 20

---------
For student 1
Enter roll no: 2
Enter name: Anjora Tripathi
Enter course: MBBS
Enter marks: 30 30 30

---------
For student 2
Enter roll no: 3
Enter name: Kunal Singh Chuhan
Enter course: BCA 
Enter marks: 21 21 21

---------
For student 3
Enter roll no: 4
Enter name: Saloni Dubey
Enter course: BCA 
Enter marks: 23 23 23

---------
For student 4
Enter roll no: 5
Enter name: Anant Dubey
Enter course: BBA
Enter marks: 25 25 25 

---------
Detials of student 
=> 
Student details: Danish Ansari ( 1 )
enrolled in course BCA
marks: 20, 20, 20

---------
Detials of student 
=> 
Student details: Anjora Tripathi ( 2 )
enrolled in course MBBS
marks: 30, 30, 30

---------
Detials of student 
=> 
Student details: Kunal Singh Chuhan ( 3 )
enrolled in course BCA
marks: 21, 21, 21

---------
Detials of student 
=> 
Student details: Saloni Dubey ( 4 )
enrolled in course BCA
marks: 23, 23, 23

---------
Detials of student 
=> 
Student details: Anant Dubey ( 5 )
enrolled in course BBA
marks: 25, 25, 25

---------

*/