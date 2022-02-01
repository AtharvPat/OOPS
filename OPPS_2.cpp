




#include <iostream>
#include <cmath>
#include <iomanip>
#include <bits/stdc++.h>
using namespace std;

class student
{
private:
    int age;

public:
    char *name;
    const int rollno;

    student(int age, char *name, int r) : rollno(r), age(age), name(name)   //initalization list for constant varilables
    {
        this->age = age;
        // shallow copy
        //  this-> name = name;

        // deep copy
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
    }

    void display()
    {
        cout << "name:- " << name << " age:- " << age << " rollno:- " << rollno << endl;
    }

    // copy constructor
    // student(student const &s) 
    // {
    //     this->age = s.age;
    //     // shallow copy
    //     // this ->name = s.name;

    //     // deep copy
    //     this->name = new char[strlen(s.name) + 1];
    //     strcpy(this->name, s.name);
    // }
};
int main()
{
    char name[] = "abcd";
    student s1(21, name, 02);
    s1.display();

    name[3] = 'e';
    student *s2 = new student(20, name, 01);
    s2->display();
    s1.display();

    // student s3(s1);
    // s3.name[0] = 's';

    // s1.display();
    // s3.display();

    // student *s4 = new student(01);
    // s4->display();
    return 0;
}
