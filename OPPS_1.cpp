CLASSES AND OBJECTS 

INBUILT CONSTRUCTORS AND DESTRUCTORS 

#include <iostream>
#include <cmath>
#include <iomanip>
#include <bits/stdc++.h>
using namespace std;

class student
{        // syntax for objects
private: // access specifier private
    int age;

public: // access specifer public
    int rollno;

    void display()
    {
        cout << "age:- " << age << " roll no:- " << rollno << endl; // funtion to display
    }
    void setage(int a)
    { // function to set age
        age = a;
    }
    int getage()
    { // function to display age
        return age;
    }

    // default constructor
    student()
    {
        cout << "constructor called!" << endl;
    }

    // parametrized constructor
    student(int rollno)
    {
        this->rollno = rollno; // use of this keyword
        cout << "2 constructor called!" << endl;
    }

    student(int a, int r){
        cout<< "constructor 3 called!"<<endl;
        this-> age = a;
        this-> rollno = r;
    }

    ~student()
    {
        cout << "destructor called! " << endl;
    }
};

int main()
{
    // creating objects statically
    student s1, s2;

    // s1.age = 20;
    // s2.age = 20;

    // s2.getage();     // to display age

    s1.rollno = 102;
    s1.setage(31);
    cout << "s1" << endl;
    s1.display();

    // cout << "display age :- " << s1.getage() << endl;

    // creating objects dynamically
    student *s4 = new student;

    //  (*s4).age = 25;

    // both are same

    s4->rollno = 101;
    s4->setage(40);
    cout << "s4" << endl;
    s4->display();

    //    cout << "display roll no :- "<< s4 -> rollno <<endl;

    // demo for parametrize constructor
    student s3(103);
    s3.setage(40);
    cout << "s3" << endl;
    s3.display();

    // demo for parametrize constructor for dynamic allocation

    student *s5 = new student(104);
    s5->setage(50);
    cout << "s5" << endl;
    s5->display();

    // copy constructor  (student s6(s3);) or  (student s6 = s3;)
    student *s6 = new student(s3);  
    cout << "s6" << endl;
    s6->display();

    student s7(*s6); // copy constructor (student *s7 = new student(*s6);)
    cout << "s7" << endl;
    s7.display();

    // destructor for dynamic allocation
    delete s6;

    return 0;
}
