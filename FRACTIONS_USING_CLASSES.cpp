


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

    void add(fraction const &b)
    {
        int lcm = this->den * b.den;
        int numerator = (b.den * this->num) + (this->den * b.num);

        this->den = lcm;
        this->num = numerator;

        this->simplify();
    }
    void sub(fraction const &b)
    {
        int lcm = this->den * b.den;
        int numerator = (b.den * this->num) - (this->den * b.num);

        this->den = lcm;
        this->num = numerator;

        this->simplify();
    }
    void mul(fraction const &b){
        this-> num = this ->num *b.num;
        this -> den = this -> den*b.den;

        this ->simplify();

    }
};

int main()
{
    fraction a(1, 2);
    fraction b(1, 4);

    a.add(b);
    a.print();
    a.sub(b);
    a.print();
    a.mul(b);
    a.print();


    return 0;
}
