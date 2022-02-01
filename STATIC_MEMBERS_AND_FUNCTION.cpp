

#include <iostream>
#include <cmath>
#include <iomanip>
#include <bits/stdc++.h>
using namespace std;

class student
{
    static int totalstudents; // static member

public:
    int rollno;
    int age;


    student()
    {
        totalstudents++;
    }

    static int gettotalstudent(){               //static function 
        return totalstudents;
    }
};
int student::totalstudents = 0; // initialize static data members

    

int main()
{
    student s1;
    student s2,s3,s4;
    s1.rollno = 20;
    s1.age = 20;

    // cout << s1.rollno << endl;
    // cout << student::totalstudents << endl;
 cout << student :: gettotalstudent();         //static  function calling 

    return 0;
}
