
#include <iostream>
#include <cmath>
#include <iomanip>
#include <bits/stdc++.h>
using namespace std;

class fraction
{
private:
    int num;
    int den;

public:

    fraction(int num, int den)
    {
        this->num = num;
        this->den = den;
    }

    void print()
    {
        // cout<< "numerator:- "<<num<<" denominator:- "<<den<<endl;

        cout << "numerator:- " << this->num << " denominator:- " << this->den << endl;
    }

    void simplify()
    {
        int gcd = 1;
        // int j = min(num,den);
        int j = min(this->num, this->den);
        for (int i = 1; i <= j; i++)
        {
            if (this->num % i == 0 && this->den % i == 0)
            {
                gcd = i;
            }
        }
        this->num = this->num / gcd;
        this->den = this->den / gcd;
    }

    //*************************************************************************************************

    // to take input in new object (fraction here) useing class name as data type

    fraction add(fraction const &b)
    {
        int lcm = this->den * b.den;
        int numerator = (b.den * this->num) + (this->den * b.num);

        // this->den = lcm;
        // this->num = numerator;
        fraction fnew(numerator, lcm);
        fnew.simplify();
        return fnew;
    }

    // addition operator " + " overloading

    fraction operator+(fraction const &b)
    {
        int lcm = this->den * b.den;
        int numerator = (b.den * this->num) + (this->den * b.num);

        // this->den = lcm;
        // this->num = numerator;
        fraction fnew(numerator, lcm);
        fnew.simplify();
        return fnew;
    }

    //*******************************************************************************************************************

    // void sub(fraction const &b)
    // {
    //     int lcm = this->den * b.den;
    //     int numerator = (b.den * this->num) - (this->den * b.num);

    //     this->den = lcm;
    //     this->num = numerator;

    //     this->simplify();
    // }

    // void mul(fraction const &b)
    // {
    //     this->num = this->num * b.num;
    //     this->den = this->den * b.den;

    //     this->simplify();
    // }

    // ****************************************************************************************************************

    // multiply operator " * " overloading

    fraction operator*(fraction const &b)
    {
        int x = this->num * b.num;
        int y = this->den * b.den;
        fraction fnew(x, y);
        fnew.simplify();
        return fnew;
    }

    // double equal ( == ) operator over loading

    bool operator==(fraction const &b)
    {
        return (this->num == b.num && this->den == b.den);
    }

    // pre increment operator (++int) over loading

    fraction &operator++() // use of refrence for nesting of pre increment operator
    {
        num = num + den;
        simplify();

        return *this;
    }

    // post increment operator (int++) over loading
    fraction operator++(int)
    {
        fraction fnew(num, den);
        num = num + den;
        simplify();
        fnew.simplify();
        return fnew;
    }

    // "+=" operator over laoding

    fraction &operator+=(fraction &b)
    {
        int lcm = this->den * b.den;
        int numerator = (b.den * this->num) + (this->den * b.num);

        this->den = lcm;
        this->num = numerator;
        simplify();
        return *this;
    }
};

int main()
{
    fraction a(1, 2);
    fraction g(1, 2);
    fraction b(1, 4);

    fraction c = a.add(b);

    fraction d = a + b;

    fraction e = a * b;

    a.print();
    b.print();
    c.print();
    d.print();
    a.print();
    e.print();

    if (a == a)
    {
        cout << " equal " << endl;
    }
    else
    {
        cout << " not equal " << endl;
    }

    if (a == b)
    {
        cout << " equal " << endl;
    }
    else
    {
        cout << " not equal " << endl;
    }

    ++(++a);
    // cout<<"pre increment "<<++a<<endl;
    a.print();

    b++;
    fraction f = b++;
    b.print();
    f.print();

    (g += b) += b;
    g.print();

    return 0;
}
