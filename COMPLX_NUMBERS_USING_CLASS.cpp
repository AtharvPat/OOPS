#include <iostream>
#include <cmath>
#include <iomanip>
#include <bits/stdc++.h>
using namespace std;

class ComplexNumbers
{
    // Complete this class
private:
    int a, b;

public:
    ComplexNumbers(int a, int b)
    {
        this->a = a;
        this->b = b;
    }

    void print()
    {
        cout << this->a << " + i" << this->b << endl;
    }

    void plus(ComplexNumbers const &c2)
    {
        this->a = (a + c2.a);
        this->b = (b + c2.b);
    }

    void multiply(ComplexNumbers const &c2)
    {
        int x = (this->a * c2.a) - (this->b * c2.b);
        int y = (this->a * c2.a) + (this->b * c2.b);

        a = x;
        b = y;
    }
};

int main()
{
    int real1, imaginary1, real2, imaginary2;

    cin >> real1 >> imaginary1;
    cin >> real2 >> imaginary2;

    ComplexNumbers c1(real1, imaginary1);
    ComplexNumbers c2(real2, imaginary2);

    int choice;
    cin >> choice;

    if (choice == 1)
    {
        c1.plus(c2);
        c1.print();
    }
    else if (choice == 2)
    {
        c1.multiply(c2);
        c1.print();
    }
    else
    {
        return 0;
    }
}
